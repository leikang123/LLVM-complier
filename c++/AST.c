#include <iostream>
#include <stdio.h>
#define MAX 100
#define MaxVtNum 20
#define MaxVnNum 20
#define MaxPlength 20
using namespace std;
struct product
{
    int length;
    char left;
    char right[MaxPlength];

}p[100];
struct set    /*产生结构体*/
{
    int n;
    char elm[100];
}first[MAX],follow[MAX];
char termin[MaxVtNum];
char non_termin[MaxVnNum];
int n;
int VtNum;
int VnNum;  /*非终结符数量*/
inline bool isterminal(char x)
{
    if(x>='A' && x<='Z')
       return false;
       return true;
}
bool exist(char x)
{
    int i;
    if(isterminal(x))
    {
        for(i=1;i<=VtNum;i++)
           if(termin[i]==x)
           return true;
           return false;
    }
    for(i=1;i<=VnNum;i++)
       if(non_termin[i] ==x)
       return true;
       return false;
}
void read()
{
    int i,j,k;
    char tmp[25];
    printf("输入产生式数量:");
    scanf("%d",&n);
    printf("输入形如A->abc的产生式，其中-表示空:\n");
    for(VnNum=VtNum=0,i=1;i<=n;i++)
    {
        scanf("%s",tmp);
        p[i].left=tmp[0];
        if(!exist(tmp[0])) non_termin[++VnNum] =tmp[0];
        for(k=0,j=3;tmp[j];j++)
        {
            p[i].right(k++] = tmp[j];
            if(isterminal(tmp[j]))
               if(!exist(tmp[j])) 
                  termin[++VtNum]=tmp[j];
            else 
               if(!exist(tmp[j])) non_termin[++VnNum]=tmp[j];

        }
        p[i].right[k]=0;
        p[i].length=k-1; 
    }
    termin[++VtNum] = non_termin[++VnNUm] ='#';
}
void show()
{
    int i;
    printf("用户所输入的产生式为:\n");
    for(i=1;i<=n;i++)
    printf("(%d)  %c->%s\n",i,p[i].left,p[i].right);
}
/*把符号x变成对应的*/
int char_id(char x)
{
    int i;
    if(!isterminal(x))
    {
        for(i=1;i<=VnNUm;i++)
           if(non_termin[i] ==x) 
              return i;
    }
      for(i=1;i<=VtNum;i++)
         if(termin[i] ==x)
           return i+1000;
        return -1;
}
/*判断符号idt是否在st里面*/
bool in (struct set,char id)
{
    int i;
    for(i=1;i<=st;i++)
       if(st.elm[i]==id)
         return true;
        return false;
}
void add(struct set &st,char e)
{
    st.n++;
    st.elm[st.n]=e;
}
void compute_first()
{
    int i,j,k,idl,idr;
    bool inc;
    while(inc)
    {
        inc = false;
        for(i=1;i<=n;i++)
        {
            idl = char_id(p[i].left)
            for(j=0;p[i].right[j];j++)
            {
                idr = char_id(p[i].right[j]);
                if(idr>1000)
                {
                    if(!in(first[idl].p[i].right[j]))
                    {
                        add(first[idl].p[i].right[j]);
                        inc=true;
                    }
                    break;
                }
                else
                {
                    for(k=1;k<=first[idr].n;k++)
                    {
                        if(!in(first[idl].first[idr].elm[k])&&first[idr].elm[k]!='-')
                        {
                            add(first[idl].first[idl].elm[k]);
                            inc=true;
                        }
                    }
                    if(!in(first[idl],'-'))
                    break;

                }
            }
            if(p[i].right[j] ==0 && !in(first[idl],'-'))
            {
                add(first[idl],'-');
                inc=true;
            }
        }
    }
}
void printf_first(struct set *st)
{
    int i,j;
    puts("\n");
    for(i=1;i<=VnNum;i++)
    {
        printf("%s(%c):  ",FIRST,non_termin[i]);
        for(j=1;j<=st[i],n;j++)
           printf("%c  ",st[i].elm[j]);
           puts("");
    }
}
int main()
{
    read();
    show();
    compute_first();
    print_first(first);
    return 0;
}