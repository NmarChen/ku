 1 #ifndef MORSE_H_
 2 #define MORSE_H_
 3 
 4 
 5 typedef int bool;
 6 #define false 0
 7 #define true  1
 8 
 9 /*
10  *  FAKE_SPACE IS MARING FOR A SPACE
11  */
12 #define FAKE_SPACE '/'
13 
14 /*
15  * THE CHARACTER THAT BETWEEN TWO MORSE STRING
16  */
17 #define SEPARATOR ' '
18 
19 
20 typedef struct Morse Morse_t;
21 struct Morse{
22     char c[9];
23 };
24 
25 
26 
27 Morse_t *new_morse();
28 
29 bool str2morse(char m , Morse_t *morse);
30 bool morse2str(Morse_t *morse, char *ch);
31 
32 bool mark2morse(char n, Morse_t *morse);
33 bool morse2mark(Morse_t *morse, char *n);
34 
35 bool num2morse(char n, Morse_t *morse);
36 bool morse2num(Morse_t *morse, char *n);
37 
38 void MorseString2String(char *morse ,char *string, int buf_len);
39 
40 void String2MorseString(char *string ,char *morse, int buf_len);
41 
42 void str2lowcase(char *str, char *out, int buf_len);
43 
44 #endif /* MORSE_H_ */
