#include "tree_sitter/parser.h"
#include <node.h>
#include "nan.h"

using namespace v8;

extern "C" TSLanguage * tree_sitter_python();

namespace {

NAN_METHOD(New) {}

// void InitAll(Local<Object> exports) { //, Local<Object> module) {
//   Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
//   tpl->SetClassName(Nan::New("Language").ToLocalChecked());
//   tpl->InstanceTemplate()->SetInternalFieldCount(1);
//
//   Local<Function> constructor = Nan::GetFunction(tpl).ToLocalChecked();
//   Local<Object> instance = constructor->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
//   Nan::SetInternalFieldPointer(instance, 0, tree_sitter_python());
//
//   Nan::Set(instance, Nan::New("name").ToLocalChecked(), Nan::New("python").ToLocalChecked());
//   Nan::Set(module, Nan::New("exports").ToLocalChecked(), instance);
// }
// NAN_MODULE_WORKER_ENABLED(tree_sitter_python_binding, InitAll)
//


extern "C" NODE_MODULE_EXPORT void
NODE_MODULE_INITIALIZER(Local<Object> exports,
                        Local<Object> module,
                        Local<Context> context) {
  /* Perform addon initialization steps here. */
    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("Language").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Local<Function> constructor = Nan::GetFunction(tpl).ToLocalChecked();
    Local<Object> instance = constructor->NewInstance(Nan::GetCurrentContext()).ToLocalChecked();
    Nan::SetInternalFieldPointer(instance, 0, tree_sitter_python());

    Nan::Set(instance, Nan::New("name").ToLocalChecked(), Nan::New("python").ToLocalChecked());
    Nan::Set(module, Nan::New("exports").ToLocalChecked(), instance);
}

}  // namespace
