using namespace std;

void star(int i, int j, int k) {
    if((i/k)%3==1 && (j/k)%3==1) cout << " ";
    else {
        if(k/3==0) cout << "*";
        else star(i,j,k/3);
    }
}

int main() {
    int k;
    cin >> k;
    
    for(int i=0; i<k; i++) {
        for(int j=0; j<k; j++) {
            star(i,j,k);
        }
        cout << endl;
    }
}
