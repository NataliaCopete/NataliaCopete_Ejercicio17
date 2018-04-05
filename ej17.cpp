#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool Estalleno();
  int n_sobres();
  void aumentar_sobres();
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
}

bool Album::Estalleno(){
if(n_en_album==660){
return true;
}
else{return false;
}
}

int Album::n_sobres(){
cout <<n_sobres_comprados<< endl;
}

void Album::aumentar_sobres(){
n_sobres_comprados+=1;
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados=0;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

int main(){
  srand(time(0));
  Album A(660);
  while(A.Estalleno()==false){
    A.CompraSobre(5);
    A.aumentar_sobres();
  }
  A.n_sobres();
}

