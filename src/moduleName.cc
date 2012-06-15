

#include <v8.h>
#include <node.h>
#include <iostream>


#include "moduleName.h"


using namespace node;
using namespace v8;
using namespace std;


// Convert a JavaScript string to a std::string.  To not bother too
// much with string encodings we just use ascii.
string ObjectToString(Local<Value> value) {
  String::Utf8Value utf8_value(value);
  return string(*utf8_value);
}



int GetArgumentIntValue ( const Arguments& args, int argNum, int &value )
{
    if (args[argNum]->IsNumber())
    {
        value = args[argNum]->Int32Value();
    } 
    else {
        cout << "GetArgumentIntValue arg " << ObjectToString(args[argNum]) << " not an integer\n";
        return PROCESS_FAIL;
    }
    return PROCESS_OK;
}


int GetArgumentDoubleValue ( const Arguments& args, int argNum, double &value )
{
    if (args[argNum]->IsNumber())
    {
        value = args[argNum]->NumberValue();
    } 
    else {
        cout << "GetArgumentDoubleValue arg " << ObjectToString(args[argNum]) << " not a number\n";
        return PROCESS_FAIL;
    }
    return PROCESS_OK;
}


int GetArgumentStringValue ( const Arguments& args, int argNum, string &value)
{
    if (args[argNum]->IsString())
    {
        value = ObjectToString(args[argNum]);    
    } 
    else {
        cout << "GetArgumentStringValue arg " << ObjectToString(args[argNum]) << " not a string\n";
        return PROCESS_FAIL;
    }
    return PROCESS_OK;

}

static Handle<Value> hello(const Arguments& args)
{
    if (args.Length() < 1) {
        return Number::New(PROCESS_FAIL);
    }
    int targ=0;
    string val;

    int status = GetArgumentStringValue ( args, targ++, val);
    if (status == PROCESS_FAIL) {
        return String::New("PROCESS FAIL");
    }

    string out = hello(val);

    return String::New(out.c_str());
}



extern "C" {
  static void init(Handle<Object> target)
  {
      NODE_SET_METHOD(target, "hello", hello);
  }

  NODE_MODULE(moduleName, init)
}