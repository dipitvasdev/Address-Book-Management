#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class Member
{
  int Mno ;
  char Name[20],Email[20],Add[20],City[20],Country[20] ;
  char Mobile[12] ;long int PostalCode ;
  public:
  void create() ;
  void show() ;
  Member(){ Mno=0 ;}
  int Rmno(){ return Mno ;}
  char* RMob(){return Mobile;}
  char* Rname(){return Name;}
  char* Remail(){return Email;}
  char* Rcity(){ return City;}
  char* Rcountry(){ return Country;}
  void EditAdd(){ cout<<"New Address:?" ; gets(Add) ;}
  void EditCity(){cout<<"New City:?" ; gets(City) ; }
  void EditCountry(){cout<<"New Country:?" ; gets(Country) ;}
  void EditEmail(){cout<<"New Email ID:?" ;gets(Email) ;}
};
int Lmno()  //function to get last member number from th record
{
  fstream F ; int j=0  ;
  Member M ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  while(F.read((char*)&M,sizeof(M)))
    j++ ;
  F.seekg(j*sizeof(M)) ;
  F.read((char*)&M,sizeof(M)) ;
  int N=M.Rmno() ;
  return N ;
}
void Member::create()
{
  Mno=Lmno()+1 ;
  cout<<"Enter Name:" ;
  gets(Name) ;
  cout<<"Enter Email:" ;
  gets(Email) ;
  cout<<"Enter Mobile Number:" ;
  gets(Mobile) ;
  cout<<"Enter Address: " ;
  gets(Add) ;
  cout<<"Enter City:" ;
  gets(City) ;
  cout<<"Enter Postal Code:" ;
  cin>>PostalCode ;
  cout<<"Enter Country:" ;
  gets(Country) ;
}
void Member::show()
{
  cout<<"Member No:"<<Mno<<endl ;
  cout<<"Name:"<<Name<<endl ;
  cout<<"Email:"<<Email;
  cout<<"    Mobile:"<<Mobile<<endl ;
  cout<<"Address:"<<Add<<endl ;
  cout<<"City:"<<City ;
  cout<<"  Postal Code:"<<PostalCode ;
  cout<<"  Country:"<<Country<<endl ;
}
void add()   //addmember
{
  fstream F ;
  Member M ;
  F.open("AddB.DAT",ios::binary|ios::app) ;
  M.create() ;
  F.write((char*)&M,sizeof(M)) ;
  cout<<"Member Added"<<endl ;
  F.close() ;
}
void dispm() //display member
{
  fstream F ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  Member M ;
  while(F.read((char*)&M,sizeof(M)))
    M.show() ;
  F.close() ;
}
void deleteall() //to clear data of file
{
  fstream F;
  F.open("AddB.DAT",ios::binary|ios::out) ;
  cout<<"Done"<<endl ;
  F.close() ;
}
void deletem()    //delete specific member
{
  fstream F1,F2 ;
  Member M ; int D,c=0 ;
  cout<<"Enter Member no to be deleted"<<endl ;
  cin>>D;
  F1.open("AddB.DAT",ios::binary|ios::in) ;
  F2.open("Temp.DAT",ios::binary|ios::out) ;
  while(F1.read((char*)&M,sizeof(M)))
  {
    if(M.Rmno()!=D)
      F2.write((char*)&M,sizeof(M))  ;
    else
      c++ ;
  }
  if(!c)
    cout<<"Not Found!!"<<endl ;
  else
    cout<<"Record Deleted"<<endl ;
  F1.close() ;
  F2.close() ;
  //transfer from temp to addb
  F1.open("AddB.DAT",ios::binary|ios::out) ;
  F2.open("Temp.DAT",ios::binary|ios::in) ;
  while(F2.read((char*)&M,sizeof(M)))
    F1.write((char*)&M,sizeof(M)) ;
  F1.close() ;
  F2.close() ;
}

void modify() // modify specific details of memebers
{
  clrscr() ;
  cout<<"MODIFY::"<<endl ;
  fstream F ;
  Member M ; int sno,found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in|ios::out) ;
  cout<<"Enter Member No to be modified"<<endl ;
  cin>>sno ;
  while(!found && F.read((char*)&M,sizeof(M)))
    if(M.Rmno()==sno)
      found++ ;
  if(found)
  {
    M.show() ;
    int a;
    cout<<"/*/*/*" ;
    cout<<"What Do Want To Be Modified?"<<endl ;
    cout<<"1.Email   2.Address"<<endl ;
    cout<<"3.City    4.Country"<<endl ;
    cout<<"Enter Command-->" ; cin>>a ;
    switch(a)
    {
      case 1: M.EditEmail() ;
              int N=F.tellg()-sizeof(M) ;
              F.seekp(N) ;
              F.write((char*)&M,sizeof(M)) ;
              cout<<"Task Complete"<<endl ;
      break ;
      case 2: M.EditAdd() ;
              int N=F.tellg()-sizeof(M) ;
              F.seekp(N) ;
              F.write((char*)&M,sizeof(M)) ;
              cout<<"Task Complete"<<endl ;
      break ;
      case 3: M.EditCity() ;
              int N=F.tellg()-sizeof(M) ;
              F.seekp(N) ;
              F.write((char*)&M,sizeof(M)) ;
              cout<<"Task Complete"<<endl ;
      break ;
      case 4: M.EditCountry() ;
              int N=F.tellg()-sizeof(M) ;
              F.seekp(N) ;
              F.write((char*)&M,sizeof(M)) ;
              cout<<"Task Complete"<<endl ;
      break ;
      default:
      cout<<"***Invalid***"<<endl ;
    }
  }
  else
  cout<<"Member not found"<<endl ;
  F.close()           ;
}
void searchmno() //search on basis of member no
{
  clrscr() ;
  cout<<"SEARCH FOR MEMBER NO"<<endl ;
  fstream F ;
  Member M; int S,found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  cout<<"Enter Member No to be searched"<<endl ;
  cin>>S ;
  while(F.read((char*)&M,sizeof(M)))
  {
    if(M.Rmno()==S)
    {
      cout<<"Members Found"<<endl ;
      M.show() ;
      found++ ;
    }
  }
  if(found==0)
    cout<<"Member Not Found"<<endl ;
  F.close() ;
}
void searchnam() //search on basis of name
{
  clrscr() ;
  cout<<"SEARCH FOR MEMBER NAME"<<endl ;
  fstream F ;
  Member M; char S[20] ; int found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  cout<<"Enter Member Name to be searched"<<endl ;
  gets(S) ;
  while(F.read((char*)&M,sizeof(M)))
  {
    if(strcmpi(M.Rname(),S)==0)
    {
      cout<<"Members Found"<<endl ;
      M.show() ;
      found++ ;
    }
  }
  if(found==0)
  cout<<"Member Not Found"<<endl ;
  F.close() ;
}
void searchmob()  //search on basis on mobile
{
  clrscr() ;
  cout<<"SEARCH FOR MOBILE"<<endl ;
  fstream F ;
  Member M; char S[12],found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  cout<<"Enter Mobile No to be searched"<<endl ;
  gets(S) ;
  while(F.read((char*)&M,sizeof(M)))
  {
    if(strcmp(M.RMob(),S==0))
    {
      cout<<"Members Found"<<endl ;
      M.show() ;
      found++ ;
    }
  }
  if(found==0)
  cout<<"Member Not Found"<<endl ;
  F.close() ;
}
void searchem()        // search on basis of email
{
  clrscr() ;
  cout<<"SEARCH FOR MEMBER EMAIL"<<endl ;
  fstream F ;
  Member M; char S[20]; int found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  cout<<"Enter Email  to be searched"<<endl ;
  gets(S) ;
  while(F.read((char*)&M,sizeof(M)))
  {
    if(strcmpi(M.Remail(),S)==0)
    {
      cout<<"Member Found"<<endl ;
      M.show() ;
      found++ ;
    }
  }
  if(found==0)
  cout<<"Member Not Found"<<endl ;
  F.close() ;
}
void searchct() //search on basis of city
{
  clrscr() ;
  cout<<"SEARCH FOR MEMBER CITY"<<endl ;
  fstream F ;
  Member M; char ci[20]; int found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  cout<<"Enter City to be searched"<<endl ;
  gets(ci) ;
  while(F.read((char*)&M,sizeof(M)))
  {
    if((strcmpi(M.Rcity(),ci)==0))
    {
      cout<<"-->Member Found"<<endl ;
      M.show() ;
      found++ ;
    }
  }
  if(found==0)
    cout<<"Member Not Found"<<endl ;
  F.close() ;
}
void searchcn() //search on basis of country
{
  clrscr() ;
  cout<<"SEARCH FOR MEMBER COUNTRY"<<endl ;
  fstream F ;
  Member M; char cn[20]; int found=0 ;
  F.open("AddB.DAT",ios::binary|ios::in) ;
  cout<<"Enter Country to be searched"<<endl ;
  gets(cn) ;
  while(F.read((char*)&M,sizeof(M)))
  {
    if((strcmpi(M.Rcountry(),cn)==0))
    {
      cout<<"-->Member Found"<<endl ;
      M.show() ;
      found++ ;
    }
  }
  if(found==0)
    cout<<"Member Not Found"<<endl ;
  F.close() ;
}

void AdminMenu()
{
  int m ; clrscr() ;
  do
  {
    cout<<"***Welcome Admin****"<<endl ;
    cout<<"1.Add Member"<<endl   ;
    cout<<"2.Show Member List"<<endl ;
    cout<<"3.Delete Member"<<endl ;
    cout<<"4.Modify Member"<<endl ;
    cout<<"5.Clear Data"<<endl ;
    cout<<"6.Exit"<<endl ;
    cout<<"--> " ;
    cin>>m ;
    switch(m)
    {
      case 1: add() ;
      break ;
      case 2: dispm() ;
      break ;
      case 3: deletem() ;
      break ;
      case 4: modify() ;
      break ;
      case 5: deleteall() ;
      break ;
      case 6:
      break ;
      default:
      cout<<"***Invalid***"<<endl ;
    }
   }while(m!=6) ;
}
void searchmenu()
{
  clrscr() ;
  int i;
  do
  {
    cout<<"++++++++++++++Search++++++++++++"<<endl ;
    cout<<"1.Search for Mno"<<endl ;
    cout<<"2.Search for Name"<<endl ;
    cout<<"3.Search for Email"<<endl ;
    cout<<"4.Search for Mobile"<<endl ;
    cout<<"5.Search for City "<<endl ;
    cout<<"6.Search for Country"<<endl ;
    cout<<"7.Exit"<<endl ;
    cin>>i ;
    switch(i)
    {
      case 1:searchmno() ;
      break ;
      case 2: searchnam() ;
      break ;
      case 3: searchem() ;
      break ;
      case 4:searchmob() ;
      break ;
      case 5: searchct() ;
      break ;
      case 6: searchcn() ;
      break ;
      case 7:
      break ;
      default: cout<<"***Invalid***"<<endl ;
      break ;
    }
  }while(i!=7) ;
}
void main()
{
  int p,q ;
  do
  {
    clrscr() ;
    cout<<"*************Address Book Management System*******"<<endl  ;
    cout<<"1.Admin"<<endl ;
    cout<<"2.Search"<<endl ;
    cout<<"3.Exit"<<endl ;
    cin>>p ;
    switch(p)
    {
       case 1:AdminMenu() ;
       break ;
       case 2:searchmenu() ;
       break ;
       case 3:
       break ;
       default: cout<<"***Invalid***"<<endl ;
       break ;
    }
  }while(p!=3) ;
  getch() ;
}
