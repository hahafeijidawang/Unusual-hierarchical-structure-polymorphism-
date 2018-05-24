/*
index<0  抛出异常
*/

#include <iostream>

using namespace std;

class MyArray
{
public:
    MyArray(int len) ;

    ~MyArray();
 public:

    int & operator[](int index);

    int getLen();

    class eSize{};

    class eNegative{};

    class eTooBig{};

    class eZero{};

    class eTooSmall{};



private:

    int *m_space;

    int m_len;


};
//因为成员函数没有返回值 所以将thow 放在这里面反馈
MyArray::MyArray(int len) {

    if(len<0){

        throw eNegative();

    }else if(len ==0 ){


        throw eZero();

    }else if(len>1000){

        throw eTooBig();

    }else{

        throw  eTooSmall();

    }



    m_len = len;

    m_space = new int[len];
}
int & MyArray::operator[](int index){


    return m_space[index];


}
   int MyArray::getLen(){


       return m_len;

   }
   MyArray::~MyArray() {

       if(m_space != NULL){

           delete [] m_space;

           m_space = NULL;

           m_len = 0;
       }
   }
int main()
{
   try{

      MyArray a(-5);
      for(int i=0;i<a.getLen();i++){
          a[i] = i+1;

          printf("%d",a[i]);

    }
}
     catch(MyArray::eNegative e ){


                  cout<<"eNegative"<<endl;

          }




    catch(MyArray::eZero e ){


              cout<<"eZero"<<endl;

          }


    catch(MyArray::eTooBig e ){


              cout<<"eTooBig"<<endl;

          }

    catch(MyArray::eTooSmall e ){


              cout<<"eTooSmall"<<endl;

          }
    return 0;
}

