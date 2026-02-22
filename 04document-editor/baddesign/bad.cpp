#include <bits/stdc++.h>
using namespace std;

class DocumentEditor{
private:
    vector<string> docemement;
    string renderdocument;

public:
    void addText(string text){
        docemement.push_back(text);
    }

    void addImg(string path){
        docemement.push_back(path);
    }

    string renderDoc(){
        if(renderdocument.empty()){
            string result;
            for(auto element: docemement){
                if(element.length()>4 && element.substr(element.length()-4) == ".jpg" || element.substr(element.length()-4) == ".png"){
                    result += "[Image : " + element + "]" + "\n" ;
                }else{
                    result+=element + "\n";
                }
            }
            renderdocument = result;
        }
        return renderdocument;
    }


    void saveTofile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDoc();
            file.close();
            cout<<"Document saved to document.txt "<<endl;
        }
        else{
            cout<<"ERROR: unable to open file for writing "<<endl;
        }
    }   
};

int main(){
    DocumentEditor editor;
    editor.addText("hellow world ");
    editor.addImg("picture.jpg");
    editor.addText("This is a document editor ..");

    cout<<editor.renderDoc()<<endl;
    editor.saveTofile();

  return 0;
}
