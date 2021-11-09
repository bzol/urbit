#include "all.h"

u3_noun
u3qdu_sec(u3_noun t, u3_atom m)
{
  if ( u3_nul == t ) {
    return u3_nul;
  }
  else {
    u3_noun hol = u3h(t);

    if ( c3n == u3ud(hol) ) {
      return u3m_bail(c3__exit);
    }
    else switch ( hol ) {
      default:
        return u3m_bail(c3__exit);

      case c3__llos: {
        u3_noun n_p_t, l_p_t, m_p_t, r_p_t;

        u3x_qual(u3t(u3t(t)), &n_p_t, &l_p_t, &m_p_t, &r_p_t);

        return u3qdu_toy(u3nt(u3k(n_p_t), u3k(l_p_t), u3k(m_p_t)),
                         u3qdu_sec(u3k(r_p_t), u3k(m)));
      }

      case c3__rlos: {
        u3_noun n_p_t, l_p_t, m_p_t, r_p_t;

        u3x_qual(u3t(u3t(t)), &n_p_t, &l_p_t, &m_p_t, &r_p_t);

        return u3qdu_toy(u3qdu_sec(u3k(l_p_t), u3k(m_p_t)),
                         u3nt(u3k(n_p_t), u3k(r_p_t), u3k(m)));

      }
    }
  }
}

u3_noun
u3wdu_sec(u3_noun cor)
{
  u3_noun t, m;

  if ( (c3n == u3r_mean(cor, u3x_sam_2, &t, u3x_sam_3, &m, 0 )) ||
       (c3n == u3ud(m)) )
  {
    return u3m_bail(c3__exit);
  } else {
    return u3qdu_sec(t, m);
  }
}


