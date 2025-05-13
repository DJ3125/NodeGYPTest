#include <node_api.h>
#include <assert.h>

napi_value Hello(napi_env env, napi_callback_info info) {
  napi_value result;
  napi_status status = napi_create_string_utf8(env, "Hello from C!", NAPI_AUTO_LENGTH, &result);
  assert(status == napi_ok);
  return result;
}

napi_value Init(napi_env env, napi_value exports) {
  napi_status status;
  napi_value fn;

  status = napi_create_function(env, NULL, 0, Hello, NULL, &fn);
  assert(status == napi_ok);

  status = napi_set_named_property(env, exports, "hello", fn);
  assert(status == napi_ok);
  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
