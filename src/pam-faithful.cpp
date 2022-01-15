#include <napi.h>
#include <security/pam_appl.h>

Napi::Value PamStart(const Napi::CallbackInfo &info)
{
    return info.Env().Undefined();
}

Napi::Object init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "pam_start"), Napi::Function::New(env, PamStart));

    exports.Set(Napi::String::New(env, "PAM_PROMPT_ECHO_OFF"), Napi::Number::New(env, PAM_PROMPT_ECHO_OFF));
    exports.Set(Napi::String::New(env, "PAM_PROMPT_ECHO_ON"), Napi::Number::New(env, PAM_PROMPT_ECHO_ON));
    exports.Set(Napi::String::New(env, "PAM_ERROR_MSG"), Napi::Number::New(env, PAM_ERROR_MSG));
    exports.Set(Napi::String::New(env, "PAM_TEXT_INFO"), Napi::Number::New(env, PAM_TEXT_INFO));

    exports.Set(Napi::String::New(env, "PAM_SUCCESS"), Napi::Number::New(env, PAM_SUCCESS));
    exports.Set(Napi::String::New(env, "PAM_BAD_ITEM"), Napi::Number::New(env, PAM_BAD_ITEM));
    exports.Set(Napi::String::New(env, "PAM_BUF_ERR"), Napi::Number::New(env, PAM_BUF_ERR));
    exports.Set(Napi::String::New(env, "PAM_SYSTEM_ERR"), Napi::Number::New(env, PAM_SYSTEM_ERR));

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init);