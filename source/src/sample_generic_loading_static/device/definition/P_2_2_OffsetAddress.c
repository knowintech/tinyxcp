/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   P_2_2_OffsetAddress.h
 *
 * @remark
 *
 */

#include "P_2_2_OffsetAddress.h"

static TinyRet P_2_2_OffsetAddress_SetValueRange(Property *thiz)
{
    TinyRet ret = TINY_RET_OK;
    JsonValue * min = NULL;
    JsonValue * max = NULL;
    JsonValue * step = NULL;

    do
    {
        min = JsonValue_NewString("0000");
        if (min == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        max = JsonValue_NewString("FFFF");
        if (max == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        step = JsonValue_NewString("01");
        if (step == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }

        thiz->valueRange = ValueRange_New(min, max, step);
        if (thiz->valueRange == NULL)
        {
            ret = TINY_RET_E_NEW;
            break;
        }
    } while (false);

    if (min != NULL)
    {
        JsonValue_Delete(min);
    }

    if (max != NULL)
    {
        JsonValue_Delete(max);
    }

    if (step != NULL)
    {
        JsonValue_Delete(step);
    }

    return ret;
}

Property * P_2_2_OffsetAddress(void)
{
    Property *thiz = NULL;

    do
    {
        thiz = Property_NewInstance(2, "xiot-spec", "offset-address", 0x00000000, NULL, FORMAT_HEX, 0, NONE);
        if (thiz == NULL)
        {
            break;
        }

        if (RET_FAILED(P_2_2_OffsetAddress_SetValueRange(thiz)))
        {
            Property_Delete(thiz);
            break;
        }
    } while (false);

    return thiz;
}