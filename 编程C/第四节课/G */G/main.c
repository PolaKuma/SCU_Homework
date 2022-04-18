//
//  main.c
//  G
//
//  Created by Junjie on 2021/10/15.
//

#include <stdio.h>

int len(const char x[])
{
    int len = 0;
    while(x[len])
        len++;
    return len;
}

int main() {
    char a[100],b[100]; // 子串a和子串b
    scanf("%s", &a); //abcdefg
    scanf("%s", &b);
    if (len(a) < len(b)){
        printf("NO");
        return 0;
    }
    else
    {
        for(int i = 0; i <= len(a) - len(b); i++)
        {
            int j = 0;
            for(j = 0;j < len(b) && a[i + j] == b[j]; j++);
            if (j == len(b))
            {
                printf("YES\n");
                return 0;
            }
        }
        printf("NO\n");
        return 0;
    }
}
