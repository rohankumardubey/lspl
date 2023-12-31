/*
 * Transform.h
 *
 *  Created on: Sep 18, 2009
 *      Author: alno
 */

#ifndef _LSPL_TRANSFORMS_TRANSFORM_H_
#define _LSPL_TRANSFORMS_TRANSFORM_H_

#include "../base/Base.h"

#include "Forward.h"
#include "TransformResult.h"

#include "../text/Forward.h"

namespace lspl { namespace transforms {

/**
 * Преобразование осуществляемое правой частью шаблона.
 *
 * Преобразование является неразделяемым объектом.
 */
class LSPL_EXPORT Transform {
public:
	virtual ~Transform() {}

	/**
	 * Применить преобразование к варианту сопоставления и упаковать результат.
	 *
	 * @param matchVariant вариант сопоставления
	 * @return упакованный результат применения
	 */
	virtual TransformResult * applyAndBox( const text::MatchVariant & matchVariant ) const = 0;
	virtual TransformResult * applyAndBox( const text::MatchVariant & matchVariant, unsigned int globalattributes ) const {};
};

template< typename Result >
class LSPL_EXPORT TypedTransform : public Transform {
public:
	TypedTransform() {}
	virtual ~TypedTransform() {}

	/**
	 * Применить преобразование к варианту сопоставления.
	 *
	 * @param matchVariant вариант сопоставления
	 * @return результат применения
	 */
	virtual Result apply( const text::MatchVariant & matchVariant ) const = 0;

	virtual Result apply( const text::MatchVariant & matchVariant, unsigned int globalattributes ) const {};

	/**
	 * Применить преобразование к варианту сопоставления и упаковать результат.
	 *
	 * @param matchVariant вариант сопоставления
	 * @return упакованный результат применения
	 */
	virtual TypedTransformResult<Result> * applyAndBox( const text::MatchVariant & matchVariant ) const {
		return new TypedTransformResult<Result>( apply( matchVariant ) );
	}

	virtual TypedTransformResult<Result> * applyAndBox( const text::MatchVariant & matchVariant, unsigned int globalattributes ) const {
		return new TypedTransformResult<Result>( apply( matchVariant, globalattributes ) );
	}

};

} } // namespace lspl::transforms

#endif /* _LSPL_TRANSFORMS_TRANSFORM_H_ */
