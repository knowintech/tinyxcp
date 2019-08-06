/**
 * Copyright (C) 2013-2015
 *
 * @author jxfengzi@gmail.com
 * @date   2013-11-19
 *
 * @file   ModbusMaster.h
 *
 * @remark
 *
 */

#ifndef __ModbusMaster_H__
#define __ModbusMaster_H__

#include <product/Product.h>

TINY_BEGIN_DECLS


Product * ModbusMaster(const char *serialNumber, const char *ip);


TINY_END_DECLS

#endif /* __ModbusMaster_H__ */
