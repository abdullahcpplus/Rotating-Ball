#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;
const int width =50,  hight= 10;
int railx, raily;
int ballxx, xx,xxx, yy,yyy, hy,hyy;
int ballx, bally;
enum ctrl
{
    stop=0,
    Left,
    Right
};
ctrl dir;
void setup(){
    railx= width-3 ;
     raily = hight -2;
     ballx= width/2, 
     bally= hight/2;
     yy= width/2;
     xx= width/2;
     hy=hight/2;
}

void drow(){
    system("cls");
   for(int i=0; i<width; i++){
    cout<<"_";
   }
   cout<<endl;
   for(int i= 0; i< hight; i++){
    for(int j=0; j< width; j++){
        if(j==0  || j== width-1){
            cout<<"|";
        }
        else if(j== 6 && i!=0 && i!=1 && i!= hight -1){
            cout<<"|";
        }
        else if(j == width-6 && i!= 0 && i!= 1 && i!= hight-1){
            cout<<"|";
        }
        else if(j == ballx && i== bally){
            cout<<"o";
        }
        else{
            cout<<" ";
        }
        
    }
        cout<< endl;
   }   
   
   for (int i = 0; i < width; i++)
    {
        if(i==0 || i== width-1){
            cout<<"|";
        }
        else
        cout << "_";
    }


}
void input(){
    if(_kbhit()){
        switch (_getch())
        {
        case 'd':
            
            dir = Right;
            break;
        case 'a':
          
           dir = Left;
        default:
            break;
        }
    }
}
void logic(){
    switch (dir)
    {
    case Left:
          
         
          if(xx>6){
          ballx--;
          xx--;
          if(hy<hight-2){
            bally++;
            hy++;
            hyy=hy;
          }
          else if(hyy>2){
            bally--;
            hyy--;
            if(hyy==3){
                hy=hyy;
            }
        }

          xxx=xx;
          }
          else if(xxx<width-6){
            ballx++;
            xxx++;
            if(hy<hight-2){
                bally++;
                hy++;
                hyy=hy;
              }
              else if(hyy>2){
                bally--;
                hyy--;
                if(hyy==3){
                    hy=hyy;
                }
            }
    
            if(xxx==width-7){
            xx=xxx;          
               }
        }
      break;
    case Right:
          if(yy<width-6){
          ballx++;
          yy++;
          if(hy<hight-2){
            bally++;
            hy++;
            hyy=hy;
          }
          else if(hyy>2){
            bally--;
            hyy--;
            if(hyy==3){
                hy=hyy;
            }
        }

          yyy=yy;
          }
          else if(yyy>6){
            ballx--;
            yyy--;
            if(hy<hight-2){
                bally++;
                hy++;
                hyy=hy;
              }
              else if(hyy>2){
                bally--;
                hyy--;
                if(hyy==3){
                    hy=hyy;
                }
            }
    
            if(yyy==7){
                yy=yyy;
            }
          }
    default:
        break;
    }


}

int main(){
    setup();
    while(true){
    drow();
    input();
    logic();
    Sleep(40);
    }
    return 0;
}