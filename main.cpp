#include <iostream>


using namespace std;

const int dimensioneMax=25;

//prototipi
void mediaMaterie(float v[], float v1[], float &mediaMat, float &mediaInf);
void maggioreInf(string v[], float v1[], float mediaInf);
void minMat(string v[], float v1[], float mediaMat);
void maggioreAss(string v[], float v1[], float v2[]);
void ricercaStudente(string v[], float v1[], float v2[]);
void statistiche(float v1[], float v2[]);
int Menu();


int main() {

  string STUD[dimensioneMax]={"Mario", "Giuseppe", "Luigi", "Paolo", "Francesco",
   "Giovanni", "Antonio", "Angelo", "Salvatore", "Carlo",
   "Maria", "Anna", "Giuseppina", "Rosa", "Giovanna",
   "Carmela", "Angela", "Teresa", "Lucia", "Caterina",
   "Roberto", "Luca", "Andrea", "Stefano", "Marco"};

  float MATE[dimensioneMax]={4, 5, 6, 6.5, 7.32, 4.5, 2, 10, 9.5, 3.45, 8, 8.45, 7.89, 10, 9.75, 9, 7.68, 5.09, 6.78, 10, 10, 9, 4, 9.80, 10};
  
  float INFO[dimensioneMax]={4, 2, 6.7, 6.5, 7.32, 4.5, 6, 10, 9.5, 9.45, 7, 6.45, 3.56, 10, 9.75, 9, 8, 5.09, 6.78, 10, 10, 9, 4, 9.80, 10};

  int scelta;
  float mediaMat=0.00;
  float mediaInf=0.00;

  
  do{
    scelta=Menu();
    switch(scelta) {
      case 1:
        mediaMaterie(MATE,INFO,mediaMat,mediaInf);
        cout<<endl;
        cout<<"La media di matematica e' : "<<mediaMat<<endl;
        cout<<"La media di informatica e' : "<<mediaInf<<endl;
        cout<<endl;
      break;
      case 2:
        maggioreInf(STUD,INFO,mediaInf);
      break;
      case 3:
        minMat(STUD,MATE,mediaMat);
      break;
      case 4:
        maggioreAss(STUD,MATE,INFO);
      break;
      case 5:
        ricercaStudente(STUD,MATE,INFO);
      break;
      case 6:
        statistiche(MATE,INFO);
      break;
      case 0:
        cout<<"Esci"<<endl;
      break;
      default:
        cout<<"Attenzione, scelta sbagliata!"<<endl;
      break;
    }
  }while(scelta!=0);
  
  
  
}


int Menu() {
  int scegli;
  cout<<"-------MENU'-------"<<endl;
  cout<<"1-Media materie (Matematica e Informatica)"<<endl;
  cout<<"2-Visualizza studenti che hanno un voto maggiore della media in informatica"<<endl;
  cout<<"3-Visualizza studenti che hanno un voto inferiore alla media in matematica"<<endl;
  cout<<"4-Visualizza il nome dello studente con il voto piu' alto in matematica e di quello con il voto piu' alto in informatica"<<endl;
  cout<<"5-Ricerca studente e visualizza i voti"<<endl;
  cout<<"6-Statistiche voti studenti"<<endl;
  cout<<"0-Fine"<<endl;

  cout<<"Scegli un operazione: "<<endl;
  cin>>scegli;

  return scegli;
}



void mediaMaterie(float v[], float v1[], float &mediaMat, float &mediaInf) {

  float s=0.00;
  float s1=0.00;
  
  for(int i=0; i<dimensioneMax; i++) {
    s=s+v[i];
  }
  mediaMat=s/dimensioneMax;

  for(int i=0; i<dimensioneMax; i++) {
    s1=s1+v1[i];
  }
  mediaInf=s1/dimensioneMax;
  
}



void maggioreInf(string v[], float v1[], float mediaInf) {

  cout<<endl;

  cout<<"Studenti con il voto maggiore rispetto alla media in informatica";
  cout<<"  dove la media e' : "<<mediaInf;
  cout<<endl;
  
  for(int i=0; i<dimensioneMax; i++) {
    if(v1[i]>mediaInf) {
      cout<<"Nome: "<<v[i]<<endl;
      cout<<"Voto: "<<v1[i]<<endl;
      cout<<endl;
    }
  }

  cout<<endl;
  
}

void minMat(string v[], float v1[], float mediaMat) {
  cout<<endl;

  cout<<"Studenti con il voto inferiore rispetto alla media in matematica";
  cout<<"  dove la media e' : "<<mediaMat;
  cout<<endl;

  for(int i=0; i<dimensioneMax; i++) {
    if(v1[i]<mediaMat) {
      cout<<"Nome: "<<v[i]<<endl;
      cout<<"Voto: "<<v1[i]<<endl;
      cout<<endl;
    }
  }

  cout<<endl;
}

void maggioreAss(string v[], float v1[], float v2[]) {
  float valMax=v1[0];
  float valMax1=v2[0];
  int pos=0;
  int pos1=0;
  
  for(int i=0; i<dimensioneMax; i++) {
    if(v1[i]>valMax) {
      pos=i;
    }

    if(v2[i]>valMax1) {
      pos1=i;
    }
  }

  cout<<endl;
  cout<<"Lo studente con il voto maggiore in matematica e' : "<<v[pos]<<" mentre lo studente con il voto maggiore in informatica e' : "<<v[pos1]<<endl;
  cout<<endl;
  
}

void ricercaStudente(string v[], float v1[], float v2[]) {
  string nome;

  int i=0;


  cout<<endl;

  cout<<"Inserisci il nome dello studente: ";
  cin>>nome;
  while(i<dimensioneMax&&v[i]!=nome) {
      i=i+1;
  }

  if(i>=dimensioneMax) {
      cout<<nome<<" non e' presente tra gli studenti"<<endl;
  } else {
      cout<<nome<<" trovato "<<endl;
      cout<<"Voto matematica: "<<v1[i]<<endl;
      cout<<"Voto informatica: "<<v2[i]<<endl;


  }

  cout<<endl;
  
}

void statistiche(float v1[], float v2[]) {

  
  int matMin6=0;
  int matTra6e7=0;
  int matMagg8=0;

  
  int infMin6=0;
  int infTra6e7=0;
  int infMagg8=0;

  for(int i=0; i<dimensioneMax; i++) {
    if(v1[i]<6) {
      matMin6++;
    }
    if(v1[i]<=6||v1[i]>7) {
      matTra6e7++;
    }
    if(v1[i]>8) {
      matMagg8++;
    }
  }

  for(int i=0; i<dimensioneMax; i++) {
    if(v2[i]<6) {
      infMin6++;
    }
    if(v2[i]<=6||v2[i]>7) {
      infTra6e7++;
    }
    if(v2[i]>8) {
      infMagg8++;
    }
  }

  cout<<endl;

  cout<<"---------------STATISTICHE MATEMATICA---------------"<<endl;
  cout<<"Gli studenti con voto minore di 6 sono: "<<matMin6<<endl;
  cout<<"Gli studenti con voto compreso tra 6 e 7 sono: "<<matTra6e7<<endl;
  cout<<"Gli studenti con voto maggiore a 8 sono: "<<matMagg8<<endl;

  cout<<endl;

  cout<<"---------------STATISTICHE INFORMATICA---------------"<<endl;
  cout<<"Gli studenti con voto minore di 6 sono: "<<infMin6<<endl;
  cout<<"Gli studenti con voto compreso tra 6 e 7 sono: "<<infTra6e7<<endl;
  cout<<"Gli studenti con voto maggiore a 8 sono: "<<infMagg8<<endl;

  cout<<endl;

  
  
}
