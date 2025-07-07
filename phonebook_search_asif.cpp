%%writefile phonebook_search.cu
#include <bits/stdc++.h>
using namespace std;
#include <cuda.h>

struct Contact{
    char name[65];
    char phone_number[65];
};


string getInput(ifstream& file){
    string ans;
    char c;
    int readSuru = 0;
    while(file.get(c)){
        if(c == '\"'){
            if(readSuru == 1) break;
            readSuru = 1;
        }else{
            if(readSuru){
                ans.push_back(c);
            }
        }
    }
    return ans;
}

__device__ bool check(char* str1, char* str2){
    for(int i = 0; str1[i] != '\0'; i++){
        int flag = 1;
        for(int j = 0; str2[j] != '\0' ; j++){
            if(str1[i + j] != str2[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1) return true;
    }
    return false;
}


__global__ void myKernel(Contact* phoneBook, char* pat, int offset){
    int threadNumber = threadIdx.x + offset;
    if(check(phoneBook[threadNumber].name, pat)){
        printf("%s %s\n", phoneBook[threadNumber].name, phoneBook[threadNumber].phone_number);
    }
}



int main(int argc, char* argv[])
{
    int threadLimit = atoi(argv[2]);

    ifstream myfile("/content/drive/MyDrive/Parallel Processing Lab/labtest_dataset1.txt");
    vector<Contact> phoneBook;

    int count = 0;

    while(myfile.peek() != EOF){

        if(count > 10000) break;
        count++;

        string name = getInput(myfile);
        string phoneNum = getInput(myfile);

        Contact c;
        strcpy(c.name, name.c_str());
        strcpy(c.phone_number, phoneNum.c_str());

        phoneBook.push_back(c);
    }

    string search_name = argv[1];
    char pat[65];
    strcpy(pat, search_name.c_str());


    char* d_pat;
    cudaMalloc(&d_pat, 65); //memory allocation
    cudaMemcpy(d_pat, pat, 65, cudaMemcpyHostToDevice); //copying to device

    int n = phoneBook.size();
    Contact* d_phoneBook;
    cudaMalloc(&d_phoneBook, n*sizeof(Contact));
    cudaMemcpy(d_phoneBook, phoneBook.data(), n * sizeof(Contact), cudaMemcpyHostToDevice);


    int bakiAche = n;
    int offset = 0;
    while(bakiAche > 0){
        int batchSize = min(threadLimit, bakiAche);
        myKernel<<<1,batchSize>>>(d_phoneBook, d_pat, offset);
        cudaDeviceSynchronize();

        bakiAche -= batchSize;
        offset += batchSize;
    }

}