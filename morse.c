1 #include "morse.h"
  2 
  3 #include <stdio.h>
  4 #include <string.h>
  5 #include <stdlib.h>
  6 
  7 #define NUM_LEN 10
  8 char num[][5] = {
  9     {'-','-','-','-','-'},//0
 10     {'.','-','-','-','-'},//1
 11     {'.','.','-','-','-'},//2
 12     {'.','.','.','-','-'},//3
 13     {'.','.','.','.','-'},//4
 14     {'.','.','.','.','.'},//5
 15     {'-','.','.','.','.'},//6
 16     {'-','-','.','.','.'},//7
 17     {'-','-','-','.','.'},//8
 18     {'-','-','-','-','.'} //9
 19 };
 20 
 21 
 22 #define MARK_LEN 17
 23 char mark[][8] = {
 24     {'.', '-', '.', '-', '.', '-', '*', '.'},//.    0
 25     {'-', '-', '-', '.', '.', '.', '*', ':'},//:
 26     {'-', '-', '.', '.', '-', '-', '*', ','},//,
 27     {'-', '.', '-', '.', '-', '.', '*', ';'},//;
 28     {'.', '.', '-', '-', '.', '.', '*', '?'},//?
 29     {'-', '.', '.', '.', '-', '*', '*', '='},//=
 30     {'.', '-', '-', '-', '-', '.', '*', '\''},//'
 31     {'-', '.', '.', '-', '.', '*', '*', '/'},///
 32     {'-', '.', '-', '.', '-', '-', '*', '!'},//!
 33     {'-', '.', '.', '.', '.', '-', '*', '-'},//-
 34     {'.', '.', '-', '-', '.', '-', '*', '_'},//_
 35     {'.', '-', '.', '.', '-', '.', '*', '"'},//"
 36     {'-', '.', '-', '-', '.', '*', '*', '('},//(
 37     {'-', '.', '-', '-', '.', '-', '*', ')'},//)
 38     {'.', '.', '.', '-', '.', '.', '-', '$'},//$
 39     {'.', '-', '.', '.', '.', '*', '*', '&'},//&
 40     {'.', '-', '-', '.', '-', '.', '*', '@'} //@    16
 41 };
 42 
 43 #define CHARACTER 26
 44 char a2[][4] = {
 45 {'.','-','*','*'},//A
 46 {'-','.','.','.'},//B
 47 {'-','.','-','.'},//C
 48 {'-','.','.','*'},//D
 49 {'.','*','*','*'},//E
 50 {'.','.','-','.'},//F
 51 {'-','-','.','*'},//G
 52 {'.','.','.','.'},//H
 53 {'.','.','*','*'},//I
 54 {'.','-','-','-'},//J
 55 {'-','.','-','*'},//K
 56 {'.','-','.','.'},//L
 57 {'-','-','*','*'},//M
 58 {'-','.','*','*'},//N
 59 {'-','-','-','*'},//O
 60 {'.','-','-','.'},//P
 61 {'-','-','.','-'},//Q
 62 {'.','-','.','*'},//R
 63 {'.','.','.','*'},//S
 64 {'-','*','*','*'},//T
 65 {'.','.','-','*'},//U
 66 {'.','.','.','-'},//V
 67 {'.','-','-','*'},//W
 68 {'-','.','.','-'},//X
 69 {'-','.','-','-'},//Y
 70 {'-','-','.','.'} //Z
 71 };
 72 
 73 Morse_t *new_morse() {
 74     Morse_t *ret;
 75     ret = (Morse_t*)malloc(sizeof(Morse_t));
 76     memset(ret->c, 0, 9);
 77     return ret;
 78 }
 79 
 80 
 81 /*
 82  *    MARK
 83  */
 84 bool mark2morse(char n, Morse_t *morse) {
 85     int a = 0;
 86 
 87     for (; a < MARK_LEN; a++) {
 88         if (mark[a][7] == n) {
 89             morse->c[0] = mark[a][0];
 90             morse->c[1] = mark[a][1];
 91             morse->c[2] = mark[a][2];
 92             morse->c[3] = mark[a][3];
 93             morse->c[4] = mark[a][4];
 94             morse->c[5] = mark[a][5];
 95             morse->c[6] = mark[a][6];
 96             return true;
 97         }
 98     }
 99     return false;
100 }
101 
102 bool morse2mark(Morse_t *morse, char *n) {
103     int a = 0;
104     for (; a < MARK_LEN; a++) {
105         if (mark[a][0] == morse->c[0] &&
106             mark[a][1] == morse->c[1] &&
107             mark[a][2] == morse->c[2] &&
108             mark[a][3] == morse->c[3] &&
109             mark[a][4] == morse->c[4] &&
110             mark[a][5] == morse->c[5] &&
111             mark[a][6] == morse->c[6] ) {
112 
113             *n = mark[a][7];
114             return true;
115         }
116     }
117     return false;
118 }
119 
120 /*
121  *    NUMBER
122  */
123 bool num2morse(char n, Morse_t *morse) {
124     int pos = n - 48;
125 
126     if (pos <= 9 && pos >= 0) {
127         morse->c[0] = num[pos][0];
128         morse->c[1] = num[pos][1];
129         morse->c[2] = num[pos][2];
130         morse->c[3] = num[pos][3];
131         morse->c[4] = num[pos][4];  
132         return true;
133     } 
134     return false;
135 }
136 
137 bool morse2num(Morse_t *morse, char *n) {
138     int i = 0;
139 
140     for (; i < NUM_LEN; i++) {
141         if (num[i][0] == morse->c[0] &&
142             num[i][1] == morse->c[1] &&
143             num[i][2] == morse->c[2] &&
144             num[i][3] == morse->c[3] &&
145             num[i][4] == morse->c[4] ) {
146 
147             *n = (char)(i + 48);
148             return true;
149         }
150     }
151     return false;
152 }
153 
154 /*
155  *    CHARACTER
156  */
157 bool str2morse(char m , Morse_t *morse) {
158     int pos = m - 97;
159     if (pos >= 0 && pos <= 25) {
160     morse->c[0] = a2[pos][0];
161     morse->c[1] = a2[pos][1];
162     morse->c[2] = a2[pos][2];    
163     morse->c[3] = a2[pos][3];
164         return true;
165     }
166     return false;
167 }
168 
169 
170 bool morse2str(Morse_t *morse, char *ch) {
171     int i = 0;
172     for (i = 0; i < CHARACTER; i++) {
173         if (a2[i][0] == morse->c[0] &&
174             a2[i][1] == morse->c[1] &&
175             a2[i][2] == morse->c[2] &&
176             a2[i][3] == morse->c[3]) { 
177 
178             *ch =  (char)(i + 97);
179             return true;
180         }
181     }
182     return false;
183 }
184 
185 
186 void MorseString2String(char *morse ,char *string, int buf_len) {
187     Morse_t *temp = new_morse();
188     int a = 0;
189     int b = 0;
190     int c = 0;
191     int len = 0;
192     char ch = '*';
193     memset(temp->c, '*', 8);
194     len = strlen(morse);
195 
196     for ( ; a < len; a ++) {
197         if (c > buf_len) {
198             printf("the string buffer is too little\n");
199             return;
200         }
201 
202         if (morse[a] != SEPARATOR && morse[a] != FAKE_SPACE)
203             temp->c[b++] = morse[a];
204         else if (morse[a] == SEPARATOR && morse[a-1] != FAKE_SPACE) {//get one charactor
205             if (true == morse2str(temp, &ch) && b < 5) {
206                 string[c++] = ch;
207             } else if (true == morse2num(temp, &ch)) {
208                 string[c++] = ch;
209             } else if (true == morse2mark(temp, &ch)) {
210                 string[c++] = ch;
211             } else {
212                 printf("has morse that not be decoded !\n");
213             }
214 
215             //clean
216             b = 0;
217             memset(temp->c, '*' ,8);
218         } else if (morse[a] == FAKE_SPACE) { //have a space
219             string[c++] = ' ';
220         }
221     } 
222 }
223 
224 void String2MorseString(char *string ,char *morse, int buf_len) {
225     int a = 0;
226     int b = 0;
227     int len = strlen(string);
228     Morse_t * temp = new_morse();
229 
230     for (; a < len; a ++ ) {
231         if (buf_len < 8 || b >= buf_len) {
232             printf("morse buffer is too litte\n");
233             break;
234         }
235 
236         if (string[a] != ' ') {
237             //if is a num 
238             if (string[a] >= '0' && string[a] <= '9') {
239                 if (true == num2morse(string[a], temp)) {
240                     morse[b++] = temp->c[0];
241                     morse[b++] = temp->c[1];
242                     morse[b++] = temp->c[2];
243                     morse[b++] = temp->c[3];
244                     morse[b++] = temp->c[4];
245                 } else {
246                     printf("encode on mumber error \n");
247                     return ;
248                 }
249             }
250             //if is a character
251             else if (string[a] >= 97 && string[a] <= 122) {
252                 if (true == str2morse(string[a], temp)) {
253                 morse[b++] = temp->c[0];
254                 if (temp->c[1] != '*')
255                     morse[b++] = temp->c[1];
256                 if (temp->c[2] != '*')
257                     morse[b++] = temp->c[2];
258                 if (temp->c[3] != '*')
259                     morse[b++] = temp->c[3];
260                 } else {
261                     printf("encode on str error \n");
262                     return ;
263                 }
264             }
265             //if is a mark
266             else if (string[a] <= 127) {
267                 if (true == mark2morse(string[a], temp)) {
268                 morse[b++] = temp->c[0]; 
269                 morse[b++] = temp->c[1];
270                 morse[b++] = temp->c[2];
271                 morse[b++] = temp->c[3];
272                 morse[b++] = temp->c[4];
273                 if (temp->c[5] != '*')
274                     morse[b++] = temp->c[5];
275                 if (temp->c[6] != '*')
276                     morse[b++] = temp->c[6];
277                 } else {
278                     printf("encode on mark error \n");
279                     return ;
280                 }
281             } else {
282                 printf("out of the morse character \n");
283                 return ;
284             }
285 
286             //clean
287             memset(temp->c, 0 , 8);
288 
289             morse[b++] = SEPARATOR;
290         
291         } else if (string[a] == ' ') { //have a space and add / to instead
292             morse[b++] = FAKE_SPACE;
293             morse[b++] = SEPARATOR;
294         }
295     }
296 
297 }
298 
299 void str2lowcase(char *str, char *out, int buf_len) {
300     int len = strlen(str);
301     int a = 0;
302 
303     if (len >= buf_len) {
304         printf("buf is to low\n");
305         return;
306     }
307 
308     for (;a < len; a++) {
309         if (str[a] >= 'A' && str[a] <= 'Z') {
310             out[a] = str[a] + 32;
311         } else {
312             out[a] = str[a];
313         }
314     }
315 }
