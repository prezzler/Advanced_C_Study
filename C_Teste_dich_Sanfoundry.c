// example 1
#include <stdio.h>
int main() {
    if(sizeof(int) > -1)
        printf("True\n");   // true
    else
        printf("False\n");
}
// Lösung: FALSE
// sizeof() return type: unsigned long 
// > vergleicht zwei GLEICHE Datentypen
// -1 wird als ein unsigned long number gehandhabt 
// -1 bedeutet in unsigned 0xFFFFFFF.... (die größte mögliche Zahl)


// example 2
#include <stdio.h>
int main() {
    float f = 0.1;
    double d = 0.1;

    if(f == 0.1) // das ist double oder?
        printf("True\n"); //true?
    else
        printf("False\n");
        printf("f = %.6f, 0.1 = %.15f", f, d );
}
// Lösung: FALSE
// C tendiert immer zu double 
// 0.1 ist daher double
// double ist präziser (15 Nachkommastellen) als float (6 Nachkommastellen) 
// Vergleichsoperator! braucht gleiche Datentypen!
// daher wird da immer false rauskommen


example 3
#include <stdio.h>
int main(){
    int a, b = 1, c = 1; // das ist ein nono doch nicht

    a = sizeof(c = ++b + 1);    // hm weiß nicht was hier passieren würde 
    // size of c? also int? ja glaub schon 
    printf("a = %d, b = %d, c = %d\n", a,b,c); // a = 4 byte? b = 2 und c = 3
}
// Lösung: a = 4, b = 1, c = 1
// sizeof() wird beim Kompilieren ausgeführt nicht bei Laufzeit
// bei Laufzeit sieht der Computer nur a = 4;


//example 4
#include <stdio.h>
int main() {
    char* p = 0; // == NUL
    *p = 'A';       // char c = 'A';// p = &c; das wäre ok gewesen
    printf("Value at p = %c\n", *p); // p = 'A'
}
// Lösung: Segmentation Fault
// p zeigt auf Null (nichts)
// *p sagt schau dir den Wert im Bereich auf den du zeigst (er zeigt auf nix)
// in diesen Wert was reinzupacken ist illegal!
// wir versuchen auf in Stelle Null was zu schreiben



#include <stdio.h>

int main() {
    int a = 1, b = 3, c = 2;
    if (a>b)
        if(b>c)
            printf("a>b and b > c\n");
    else 
        printf("something else\n");
}

//Lösung: es kommt nix raus
// weil die else zur inneren if gehört
// else gehört also immer zur "letzten" if, wenn ohne {}