/**
 * Copyright (C) 2017-2020
 *
 * @author jxfengzi@gmail.com
 * @date   2017-7-1
 *
 * @file   VerifyStartCodec.h
 *
 * @remark
 *      set tabstop=4
 *      set shiftwidth=4
 *      set expandtab
 */

#include <value/JsonString.h>
#include "VerifyStartCodec.h"

TinyRet VerifyStartCodec_EncodeQuery(JsonObject *content, QueryVerifyStart *query)
{
    RETURN_VAL_IF_FAIL(content, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(query, TINY_RET_E_ARG_NULL);

    return JsonObject_PutString(content, "public-key", query->publicKey);
}

TinyRet VerifyStartCodec_DecodeResult(ResultVerifyStart *result, JsonObject *content)
{
    TinyRet ret = TINY_RET_OK;

    RETURN_VAL_IF_FAIL(result, TINY_RET_E_ARG_NULL);
    RETURN_VAL_IF_FAIL(content, TINY_RET_E_ARG_NULL);

    do
    {
        JsonString *publicKey = JsonObject_GetString(content, "public-key");
        if (publicKey == NULL)
        {
            ret = TINY_RET_E_ARG_INVALID;
            break;
        }

        JsonString *signature = JsonObject_GetString(content, "signature");
        if (signature == NULL)
        {
            ret = TINY_RET_E_ARG_INVALID;
            break;
        }

        strncpy(result->publicKey, publicKey->value, XCP_PUBLIC_KEY_LENGTH);
        strncpy(result->signature, signature->value, XCP_SIGNATURE_LENGTH);
    } while (false);

    return ret;
}