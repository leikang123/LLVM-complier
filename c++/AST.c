#include <iostream>
#include <stdio.h>
#define MAX 100
#define MaxVtNum 20  /*终结符最大的数目*/
#define MaxVnNum 20  /*非终结符最大的数目*/
#define MaxPlength 20  /*产生式最大的长度*/
using namespace std;
/*结构体*/
struct product
{
    int length;  /*产生式右部形式文法符号的长度*/
    char left;  /*产生式左部形式文法符号的长度*/
    char right[MaxPlength]; /*产生式右部的文法符号串*/

}p[100];  
struct set    /*产生结构体*/
{
    int n;  /*first和follow集的元素个数*/
    char elm[100];  
}first[MAX],follow[MAX];
char termin[MaxVtNum];  /*终结符*/
char non_termin[MaxVnNum];  /*非终结符*/
int n;  /*产生式数量*/
int VtNum;  /*终结符数量*/
int VnNum;  /*非终结符数量*/
inline bool isterminal(char x)  /*判断是否为终结符*/
{
    if(x>='A' && x<='Z')
       return false;
       return true;
}
bool exist(char x)  /*判断x是否是出现过*/
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
void read() /*读入文法*/
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
void show() /*输出用户所输入的文法*/
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
void add(struct set &st,char e) /*符号e添加到集合st里面*/
{
    st.n++;
    st.elm[st.n]=e;
}
void compute_first()    /*求first集合*/
{
    int i,j,k,idl,idr;
    bool inc;
    while(inc)
    {
        inc = false;
        for(i=1;i<=n;i++)   /*遍历所有产生式*/
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
void printf_first(struct set *st)   /*输出每个非终结符的first集合*/
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
void compute_follow()
{
    int i,j,k,idl,idr,idf;
    bool flag,inc=true;
    add(follow[1].'#'); /*把结束标志#加入开始符号的FOLLOW集合*/
    while(inc)
    {
        inc=false;
        for(i=1;i<=n;i++)
        {
            idl=char_id(p[i].left);
            for(flag=true,j=p[i].length;j>=0;j--)
            {
                idr = char_id(p[i].right[j]);
                if(idr>1000)
                {
                    flag =false;
                    continue;
                }
                if(flag)
                {
                    for(k=1;k<=follow[id].n;k++)
                    {
                        if(!in(follow[idr],follow[idl].elm[k]))
                        {
                            add(follow[idr],follow[isl].elm[k]);
                            inc=true;
                        }
                    }
                }
                if(j<p[i].length)
                  idf=cid(p[i].right[j+1]);
                  else continue;
                  if(idf>1000)
                  {
                      if(!in(follow[idr],p[i].right[j+1]))
                      add(follow[idr],p[i].right[j+1]);
                      continue;
                  }
                  for(k=1;k<=first[idf].n;k++)
                  {
                      if(!in(follow[idr],first[idf].elm[k])&& first[idf].elm([k]!='-'))
                      {
                          add(follow[idr],first[idf].elm[k]);
                          inc=true;
                      }
                  }
            }
        }
    }
}
void print_follow(struct set *st)
{
    int i,j;
    puts("\n");
    for(i=1;i<=VnNum;i++)
    {
        printf("%s(%c):  ",FOLLOW,non_termin[i]);
        for(j=1,j<=st[i].n;j++)
          printf("%c ".st[i].elm[j]);
          puts("");
    }
}
int main() /*主函数*/
{
    read();
    show();
    compute_first();
    print_first(first);
    compute_follow();
    print_follow(follow);
    return 0;
}