#include "../../base/BaseInternal.h"

#include "Context.h"

#include "../../text/Transition.h"
#include "../../text/attributes/AttributeValue.h"

using lspl::text::attributes::AttributeKey;
using lspl::text::attributes::AttributeValue;

namespace lspl { namespace patterns { namespace matchers {

Context::Context() {
}

Context::~Context() {
}

AttributeValue Context::getAttribute( Variable variable, AttributeKey attribute ) const {
	Map::const_iterator i = map.find( variable );

	if ( i == map.end() )
		return AttributeValue::UNDEFINED;

	return i->second->getAttribute( attribute );
}

AttributeValue Context::getVariable( Variable variable ) const {
	Map::const_iterator i = map.find( variable );

	if ( i == map.end() )
		return AttributeValue::UNDEFINED;

	return AttributeValue( *i->second );
}

void Context::addAttributes( std::map<text::attributes::AttributeKey,text::attributes::AttributeValue> & attributes, const Alternative::BindingMap & bindings ) const {
	for ( Alternative::BindingMap::const_iterator it = bindings.begin(), e = bindings.end(); it != e; ++ it ) {
		AttributeKey key = it->first;
		AttributeValue value = it->second->evaluate( 0, Variable(), *this );

		if ( key == AttributeKey::UNDEFINED ) {
			for ( uint attr = 0; attr < AttributeKey::count(); ++ attr ) {
				AttributeKey k = AttributeKey( attr );
				AttributeValue v = value.getContainer().getAttribute( k );

				if ( v != AttributeValue::UNDEFINED )
					attributes.insert( std::make_pair( k, v ) );
			}
		} else {
			attributes.insert( std::make_pair( key, value ) );
		}
	}
}

} } } // namespace lspl::patterns::matchers
