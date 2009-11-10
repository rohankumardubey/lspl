/*
 * MatchingAssertions.h
 *
 *  Created on: Sep 28, 2008
 *      Author: alno
 */

#ifndef MATCHINGASSERTIONS_H_
#define MATCHINGASSERTIONS_H_

#undef NDEBUG

#include "../../main/lspl/Namespace.h"

#include "../../cute/cute.h"

#define assertMatches(text,from,to,pattern) lspl::assertions::assertMatchesImpl(text,from,to,pattern,__FILE__,__LINE__)
#define assertMatchesNS(ns,text,from,to,pattern) lspl::assertions::assertMatchesImpl(ns,text,from,to,pattern,__FILE__,__LINE__)

#define assertNoMatches(text,pattern) lspl::assertions::assertNoMatchesImpl(text,pattern,__FILE__,__LINE__)
#define assertNoMatchesNS(ns,text,pattern) lspl::assertions::assertNoMatchesImpl(ns,text,pattern,__FILE__,__LINE__)

namespace lspl { namespace assertions {

void assertMatchesImpl( const char * textSource, uint from, uint to, const char * patternSource, char const *f, int line );

void assertMatchesImpl( const NamespaceRef & ns, const char * textSource, uint from, uint to, const char * patternSource, char const *f, int line );

void assertNoMatchesImpl( const char * textSource, const char * patternSource, char const *f, int line );

void assertNoMatchesImpl( const NamespaceRef & ns, const char * textSource, const char * patternSource, char const *f, int line );

} }

#endif /* MATCHINGASSERTIONS_H_ */
