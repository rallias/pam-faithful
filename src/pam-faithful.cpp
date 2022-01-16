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

    exports.Set(Napi::String::New(env, "PAM_SILENT"), Napi::Number::New(env, PAM_SILENT));
    exports.Set(Napi::String::New(env, "PAM_DISALLOW_NULL_AUTHTOK"), Napi::Number::New(env, PAM_DISALLOW_NULL_AUTHTOK));

    exports.Set(Napi::String::New(env, "PAM_SUCCESS"), Napi::Number::New(env, PAM_SUCCESS));
    exports.Set(Napi::String::New(env, "PAM_ABORT"), Napi::Number::New(env, PAM_ABORT));
    exports.Set(Napi::String::New(env, "PAM_AUTHINFO_UNAVAIL"), Napi::Number::New(env, PAM_AUTHINFO_UNAVAIL));
    exports.Set(Napi::String::New(env, "PAM_AUTH_ERR"), Napi::Number::New(env, PAM_AUTH_ERR));
    exports.Set(Napi::String::New(env, "PAM_BAD_ITEM"), Napi::Number::New(env, PAM_BAD_ITEM));
    exports.Set(Napi::String::New(env, "PAM_BUF_ERR"), Napi::Number::New(env, PAM_BUF_ERR));
    exports.Set(Napi::String::New(env, "PAM_CONV_ERR"), Napi::Number::New(env, PAM_CONV_ERR));
    exports.Set(Napi::String::New(env, "PAM_CRED_INSUFFICIENT"), Napi::Number::New(env, PAM_CRED_INSUFFICIENT));
    exports.Set(Napi::String::New(env, "PAM_MAXTRIES"), Napi::Number::New(env, PAM_MAXTRIES));
    exports.Set(Napi::String::New(env, "PAM_PERM_DENIED"), Napi::Number::New(env, PAM_PERM_DENIED));
    exports.Set(Napi::String::New(env, "PAM_SERVICE_ERR"), Napi::Number::New(env, PAM_SERVICE_ERR));
    exports.Set(Napi::String::New(env, "PAM_SYSTEM_ERR"), Napi::Number::New(env, PAM_SYSTEM_ERR));
    exports.Set(Napi::String::New(env, "PAM_USER_UNKNOWN"), Napi::Number::New(env, PAM_USER_UNKNOWN));

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, init);