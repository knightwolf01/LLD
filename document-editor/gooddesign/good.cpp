#include <bits/stdc++.h>
using namespace std;

class documentElement{
public:
    virtual string render() = 0;
};

class textElement: public documentElement{
private:
    string text;
public:
    textElement(string text){
        this->text = text;
    }
    string render() override{
        return text;
    }
};

class imageElement: public documentElement{
private:
    string path;
public:
    imageElement(string path){
        this->path = path;
    }
    string render() override{
        return "[Image :"+path+"]";
    }
};

//new line and tab space 

class NewLineElement : public documentElement {
public:
    string render() override {
        return "\n";
    }
};

class TabSpaceElement : public documentElement {
public:
    string render() override {
        return "\t";
    }
};

class Document{
private:
    vector<documentElement*> elements;
public:
    void addElement(documentElement* element){
        elements.push_back(element);
    }

    string render(){
        string result;
        for(auto elm:elements){
            result += elm->render();
        }
        return result;
    }
};

//presistence abstract 
class Persistence{
public:
    virtual void save(string s) = 0;
};

class FileStorage : public Persistence{
public:
    void save(string data ) override{
        ofstream outFile("document.txt");
        if(outFile){
            outFile << data;
            outFile.close();
            cout<<"Documet saved to document.txt file :"<<endl;
        }
        else{
            cout<<"Error: in opening file !!"<<endl;
        }
    }
};
class DBStorage : public Persistence {
public:
    void save(string data) override {
        // Save to DB
        //write your logic here .... for scalability 
    }
};

class DocumentEditor{
private:
    Document* document;
    Persistence* storage;
    string renderDocument;
public:
    DocumentEditor(Document* document, Persistence* storage){
        this->document = document;
        this->storage = storage;
    }
    //add-Text
    void addText(string text){
        document->addElement(new textElement(text));
    }
    //add image
    void addImage(string image){
        document->addElement(new imageElement(image));
    }
    //add new line
    void newline(){
        document->addElement(new NewLineElement());
    }
    //add tab space
    void tabspace(){
        document->addElement(new TabSpaceElement());
    }
    //render

    string renderdocument(){
        if(renderDocument.empty()){
            renderDocument = document->render();
        }
        return renderDocument;
    }

    void saveDocument(){
        storage->save(renderdocument());
    }

};

int main(){

    Document* document = new Document();
    Persistence* storage = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document,storage);

    editor->addText("Helllooo world !!");
    editor->newline();
    editor->addImage("Picture.jpg");

    editor->tabspace();
    editor->addText("This is a real-world document editor example.");
    editor->newline();
    editor->addText("Indented text after a tab space.");
    editor->newline();
    editor->addImage("picture.jpg");

    //render the document 
    cout<<editor->renderdocument()<<endl;
    editor->saveDocument();

  return 0;
}
