#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*Do not remove this unless you want endless amounts of errors*/

/*#include "Operator.cpp"
#include "MinusOperator.cpp"
#include "MultiplyOperator.cpp" 
#include "PlusOperator.cpp"
#include "Node.cpp" 
#include "Stack.cpp"
#include "Calculator.cpp"*/

// Include cpp files in the .h files for this linking style to work.

#include "Operator.h"
#include "MinusOperator.h"
#include "MultiplyOperator.h"
#include "PlusOperator.h"
#include "Node.h"
#include "Stack.h"
#include "Calculator.h"

static void test1();
static void test2();
static void test3();
static void test4();

int main(){

    test1();
    test2();
    test3();
    test4();
}

static void test1(){
    cout << "------------- TESTING STACK ---------------" << endl;
    int count = 0;
    Stack<int>* ptIntStack = new Stack<int>();
    if(ptIntStack->getTop() == NULL && ptIntStack->isEmpty()){
        cout << "Constructor Works and isEmpty." << endl;
    }
    else{
        cout << "Fix Constructor and isEmpty" << endl;
    }

    cout << "The Stack Size: " << ptIntStack->size() << endl;
    if(ptIntStack->contains(3) == false){
        cout << "Contains Works" << endl;
    }  
    else{
        cout << "Fix Contain Method\n";
    }

    ptIntStack->push(7);
    ptIntStack->push(23);
    if(ptIntStack->contains(7)){
        cout << "Contains Works - Stack contains 7 and contains returns true" << endl;
    }
    else{
        cout << "Fix Contain Method\n";
    }

    cout << "Printing the Stack: ";
    Node<int>* tempNode = ptIntStack->getTop();
count = 0;
    while(tempNode){
        cout << "Node " << ++count << " : " << tempNode->getData() << "\n";
        tempNode = tempNode->getNext();
    }

    cout << endl << "Testing pop: Should be 27 : " << ptIntStack->pop()->getData() << endl;
    ptIntStack->push(90);
    ptIntStack->push(12);
    ptIntStack->push(34);
    ptIntStack->push(4);
    ptIntStack->push(68);

    cout << "Done pushing" << endl;
    cout << "Printing the Stack: \n";

    tempNode = ptIntStack->getTop();
    count = 0;
    while(tempNode != NULL) {
  
        cout <<  " Node : " << ++count << " : " << tempNode->getData() << "\n";
        tempNode = tempNode->getNext();
    }
    cout << endl;

    cout << "The OG Stack Size: " << ptIntStack->size() << endl;

    Stack<int>* ptIntStack2 = ptIntStack->reverse();
    cout << "Printing the Reversed Stack (ptIntStack) : ";
    tempNode = ptIntStack2->getTop();
    count = 0;
    while(tempNode != NULL) {
        cout <<  " Node : " << ++count << " : " << tempNode->getData() << "\n";
        tempNode = tempNode->getNext();
    }
    cout << endl;

    cout << "The Reversed Stack Size: " << ptIntStack2->size() << endl;

    cout << "Printing the original stack to check if it was altered: \n";

    tempNode = ptIntStack->getTop();
    while(tempNode){
        cout << tempNode->getData() << " ";
        tempNode = tempNode->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << ptIntStack->size() << endl;
    if(ptIntStack->contains(47)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Testing pop: " << ptIntStack->pop()->getData() << endl;
    cout << "Testing pop1: " << ptIntStack->pop()->getData() << endl;
    cout << "Testing pop2: " << ptIntStack->pop()->getData() << endl;
    cout << "The Stack Size: " << ptIntStack->size() << endl;
    cout << "------------------ DONE --------------------" << endl;
    delete tempNode;
    delete ptIntStack;
    delete ptIntStack2;
}
static void test2(){
    cout << "------------- TESTING CALCULATOR ---------------" << endl;
    MinusOperator<int>* MinusOp = new MinusOperator<int>();
    PlusOperator<int>* PlusOp = new PlusOperator<int>();
    Calculator<int>* CalcPtr = new Calculator<int>();
    cout << "Testing addValue" << endl;
    CalcPtr->addValue(3);
    CalcPtr->addValue(2);
    CalcPtr->addValue(1);
    cout << "Testing addOperator" << endl;
    CalcPtr->addOperator(MinusOp);
    CalcPtr->addOperator(PlusOp);
    cout << "Testing numValues" << CalcPtr->numValues() << endl;
    cout << "Testing numOperators" << CalcPtr->numOperators() << endl;
    cout << "----------- Testing Calculate -----------" << endl;
    int calculateVal = CalcPtr->calculate();
    cout << "Calculator Value: " << calculateVal << endl;
    cout << "Calculator Value 1: " << CalcPtr->removeValue() << endl;
    cout << "-------------------- DONE ----------------------" << endl;
    delete MinusOp;
    delete PlusOp;
    delete CalcPtr;
}
static void test3(){
    cout << "------------- TESTING STACK - T->Double ---------------" << endl;
    Stack<double>* ptDoubleStack = new Stack<double>();
    if(ptDoubleStack->getTop() == NULL && ptDoubleStack->isEmpty()){
        cout << "Constructor Works and isEmpty." << endl;
    }
    else{
        cout << "Fix Constructor and isEmpty" << endl;
    }
    cout << "The Stack Size: " << ptDoubleStack->size() << endl;
    if(ptDoubleStack->contains(3.6) == false){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    ptDoubleStack->push(7.32);
    ptDoubleStack->push(98.65);
    if(ptDoubleStack->contains(7.32)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Printing the Stack: ";
    Node<double>* temp = ptDoubleStack->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl << "Testing pop: " << ptDoubleStack->pop()->getData() << endl;
    ptDoubleStack->push(0.9);
    ptDoubleStack->push(2.27);
    ptDoubleStack->push(3.4);
    ptDoubleStack->push(47.11);
    ptDoubleStack->push(1.068);
    cout << "Done pushing" << endl;
    cout << "Printing the Stack: ";
    temp = ptDoubleStack->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << ptDoubleStack->size() << endl;
    Stack<double>* ptDoubleStack2 = ptDoubleStack->reverse();
    cout << "Printing the Reversed Stack: ";
    temp = ptDoubleStack2->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << ptDoubleStack->size() << endl;
    cout << "Printing the Stack to check if it was altered: ";
    temp = ptDoubleStack->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << ptDoubleStack->size() << endl;
    if(ptDoubleStack->contains(47.11)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Testing pop: " << ptDoubleStack->pop()->getData() << endl;
    cout << "Testing pop1: " << ptDoubleStack->pop()->getData() << endl;
    cout << "Testing pop2: " << ptDoubleStack->pop()->getData() << endl;
    cout << "The Stack Size: " << ptDoubleStack->size() << endl;
    delete temp;
    delete ptDoubleStack;
    delete ptDoubleStack2; 
    cout << "-------------------- DONE ----------------------" << endl;
} 
static void test4(){
    cout << "------------- TESTING CALCULATOR - T->Double ---------------" << endl;
    MinusOperator<double>* MinusOp = new MinusOperator<double>();
    PlusOperator<double>* PlusOp = new PlusOperator<double>();
    Calculator<double>* CalcPtr = new Calculator<double>();
    cout << "Testing addValue" << endl;
    CalcPtr->addValue(3.3);
    CalcPtr->addValue(2.01);
    CalcPtr->addValue(0.1);
    cout << "Testing addOperator" << endl;
    CalcPtr->addOperator(MinusOp);
    CalcPtr->addOperator(PlusOp);
    cout << "Testing numValues" << CalcPtr->numValues() << endl;
    cout << "Testing numOperators" << CalcPtr->numOperators() << endl;
    cout << "----------- Testing Calculate -----------" << endl;
 
    double calculateVal = CalcPtr->calculate();
    cout << "Calculator Value == " << calculateVal << endl;
     
    cout << "Calculator Value 1 == " << CalcPtr->removeValue() << endl;
    delete MinusOp;
    delete PlusOp;
    delete CalcPtr;
    cout << "-------------------- DONE ----------------------" << endl;
}   