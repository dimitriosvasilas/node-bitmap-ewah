#include <nan.h>
#include <node.h>
#include "EWAHBitMap.h"
#include "src/EWAHBoolArray/headers/ewah.h"

using namespace v8;
using namespace std;

Nan::Persistent<Function> EWAHBitMap::constructor;
Nan::Persistent<FunctionTemplate> EWAHBitMap::constructor_template;

void EWAHBitMap::Init() {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("EWAHBitMap").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    constructor_template.Reset(tpl);
    constructor.Reset(tpl->GetFunction());
}

void EWAHBitMap::New(const Nan::FunctionCallbackInfo<Value>& info) {
    Nan::HandleScope scope;

    EWAHBitMap *ewahbitmap = new EWAHBitMap();
    ewahbitmap->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
}

Local<Object> EWAHBitMap::NewInstance(Local<Value> arg) {
    Nan::EscapableHandleScope scope;
    const unsigned argc = 1;
    Local<Value> argv[argc] = { arg };
    Local<Function> cons = Nan::New<Function>(constructor);
    Local<Object> instance = cons->NewInstance(argc, argv);
    return scope.Escape(instance);
}
