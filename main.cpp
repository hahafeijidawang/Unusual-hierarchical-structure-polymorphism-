//优化05241的代码用继承来做。

#include <iostream>

using namespace std;

class MyArray
{
public:

    MyArray(int len) ;

    ~MyArray();
public:

    int& operator[](int index);

    int getLen();

 class eSize{
   public:
       eSize( int size){

             m_size=size;

         }

         virtual void printErr(){

             cout<<"size:"<<m_size<<endl;
         }
      protected:

         int m_size;

     };

    class eNegative:public eSize{

    public:
        eNegative(int size):eSize(size){

            ;

        }

        virtual void printErr(){

            cout<<"eNegative:"<<m_size<<endl;
        }
    };

    class eTooBig:public eSize{

       public:

        eTooBig(int size):eSize(size){

            ;

        }

        virtual void printErr(){

            cout<<"eTooBig:"<<m_size<<endl;
        }

    };

    class eZero:public eSize{

       public:

        eZero(int size):eSize(size){

            ;

        }
        virtual void printErr(){

            cout<<"eZero:"<<m_size<<endl;
        }




    };

    class eTooSmall:public eSize{

    public:

        eTooSmall(int size):eSize(size){

            ;

        }
        virtual void printErr(){

            cout<<"eTooSmall:"<<m_size<<endl;
        }
    };

private:

    int *m_space;

    int m_len;


};
//因为成员函数没有返回值 所以将thow 放在这里面反馈


MyArray::MyArray(int len) {

    if(len<0){

        throw eNegative(len);

    }else if(len ==0 ){


        throw eZero(len);

    }else if(len>1000){

        throw eTooBig(len);

    }else{

        throw  eTooSmall(len);

    }

    m_len = len;

    m_space = new int[len];
}
 //int& operator[](int index)

int& MyArray::operator[](int index)

{


    return m_space[index];


}
   int MyArray::getLen()
  {

       return m_len;

   }

   MyArray::~MyArray() {

       if(m_space != NULL){

           delete [] m_space;

           m_space = NULL;

           m_len = 0;
       }
   }
int  main()

{
   try{

      MyArray a(0);
      for(int i=0;i<a.getLen();i++){
          a[i] = i+1;

          printf("%d",a[i]);

    }
}
    catch(MyArray::eSize &e){

       // cout<<"len的大小"<<e.eSize();
        e.printErr();



    }
//     catch(MyArray::eNegative e ){


//         cout<<"eNegative"<<endl;

//          }




//    catch(MyArray::eZero e ){


//              cout<<"eZero"<<endl;

//          }


//    catch(MyArray::eTooBig e ){


//              cout<<"eTooBig"<<endl;

//          }

//    catch(MyArray::eTooSmall e ){


//              cout<<"eTooSmall"<<endl;

//          }

return 0;
}


