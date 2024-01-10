#include <iostream>
#include <map>
#include <string>
#include <queue>

using namespace std;

map<string, string*> nama_var;

string nama= "Saya";
string reseller = "Paijo";
string nama_pertama="Gede";

void display_nama(){
//

}

int cari(string nama){

queue<string> followers;
for(int i=0; i <= (sizeof(nama_var[nama])/sizeof(int)); i++){
    followers.push(nama_var[nama][i]);
}


while(!followers.empty()){
    nama_pertama = followers.front();
    cout<<nama_pertama<<endl;
    if(nama_pertama == reseller){
        cout<<"Ketemu nama resellernya si: "<<nama_pertama<<endl;

        return 1;
    }else if(nama_var.find(nama_pertama)!= nama_var.end()){

        for(int j=0; j <= (sizeof(nama_var[nama_pertama])/sizeof(int)); j++){
            followers.push(nama_var[nama_pertama][j]);
        }
        followers.pop();
    }else{
        followers.pop();
    }

}
cout<<"Ga ada reseller di list follower ini"<<endl;
return 1;

}

int main(){


string teman_saya[3] = {"Ary", "Edy", "Tommy"};
string teman_ary[3] = {"Desy", "Yuly"};
string teman_edy[3] = {"Budi"};
string teman_tomy[3] = {"Gede", "Agus"};


nama_var["Saya"] = teman_saya;
nama_var["Ary"] = teman_ary;
nama_var["Edy"] = teman_edy;
nama_var["Tommy"] = teman_tomy;


for(auto element:nama_var){
    cout<<"Nama User: "<<element.first<<" ,Nama Follower:";

    for(int i=0; i <= sizeof(element.second)/sizeof(int); i++){
        cout<<" "<<element.second[i]<<" "<<sizeof(element.second)/sizeof(int);
    }

    cout<<endl;
}

cout<<endl;
cout<<"==========================================================="<<endl;

cari(nama);


}
