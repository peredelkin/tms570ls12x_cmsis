/*
 * user_assert.h
 *
 *  Created on: 1 авг. 2019 г.
 *      Author: ruslan
 */

#ifndef INCLUDE_STATIC_ASSERT_H_
#define INCLUDE_STATIC_ASSERT_H_

#include <assert.h>

#define STATIC_ASSERT(COND,MSG) static int static_assertion_##MSG[(COND)?1:-1]

#endif /* INCLUDE_STATIC_ASSERT_H_ */
