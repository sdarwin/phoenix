
#if !defined(BOOST_PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef BOOST_PHOENIX_CORE_EXPRESSION_HPP
#define BOOST_PHOENIX_CORE_EXPRESSION_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/phoenix/core/detail/expression.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/proto/domain.hpp>
#include <boost/proto/make_expr.hpp>
#include <boost/proto/transform/pass_through.hpp>

#include <boost/phoenix/core/preprocessed/expression.hpp>

#endif
#else

#if !BOOST_PHOENIX_IS_ITERATING

#ifndef BOOST_PHOENIX_CORE_EXPRESSION_HPP
#define BOOST_PHOENIX_CORE_EXPRESSION_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/phoenix/core/detail/expression.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/proto/domain.hpp>
#include <boost/proto/make_expr.hpp>
#include <boost/proto/transform/pass_through.hpp>

#if defined(__WAVE__) && defined(BOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/expression_" BOOST_PHOENIX_LIMIT_STR ".hpp")
#endif

/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(BOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

namespace boost { namespace phoenix
{
    template <typename Expr> struct actor;
    
    template <
        template <typename> class Actor
      , typename Tag
      , BOOST_PHOENIX_typename_A_void(BOOST_PHOENIX_COMPOSITE_LIMIT)
      , typename Dummy = void>
    struct expr_ext;

    template <
        typename Tag
      , BOOST_PHOENIX_typename_A_void(BOOST_PHOENIX_COMPOSITE_LIMIT)
      , typename Dummy = void
    >
    struct expr : expr_ext<actor, Tag, BOOST_PHOENIX_A(BOOST_PHOENIX_COMPOSITE_LIMIT)> {};

    struct default_domain_with_basic_expr
        : proto::domain<proto::use_basic_expr<proto::default_generator> >
    {};

#define BOOST_PHOENIX_ITERATION_PARAMS                                          \
    (3, (1, BOOST_PHOENIX_COMPOSITE_LIMIT,                                      \
    <boost/phoenix/core/expression.hpp>))                                       \
/**/
    #include BOOST_PHOENIX_ITERATE()

}}

#if defined(__WAVE__) && defined(BOOST_PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
    template <template <typename> class Actor, typename Tag, BOOST_PHOENIX_typename_A>
    struct expr_ext<Actor, Tag, BOOST_PHOENIX_A>
        : proto::transform<expr_ext<Actor, Tag, BOOST_PHOENIX_A>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , default_domain_with_basic_expr
              , BOOST_PHOENIX_A
            >::type
            base_type;

        typedef Actor<base_type> type;

        typedef
            typename proto::nary_expr<Tag, BOOST_PHOENIX_A>::proto_grammar
            proto_grammar;
        
        static type make(BOOST_PHOENIX_A_a)
        {
            actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , default_domain_with_basic_expr
                    >(BOOST_PHOENIX_a)
                };
            return e;
        }

        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::detail::pass_through_impl<expr_ext, Expr, State, Data>
        {};
        
        typedef Tag proto_tag;
    #define BOOST_PHOENIX_ENUM_CHILDREN(_, N, __)                               \
        typedef BOOST_PP_CAT(A, N) BOOST_PP_CAT(proto_child, N);                \
    /**/
        BOOST_PP_REPEAT(BOOST_PHOENIX_ITERATION, BOOST_PHOENIX_ENUM_CHILDREN, _)
    #undef BOOST_PHOENIX_ENUM_CHILDREN
    };

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
