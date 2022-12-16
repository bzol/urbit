/* vere/loop.c
**
*/
#include "all.h"
#include "vere/vere.h"

/* u3_loop: opengl graphics
*/
  typedef struct _u3_loop {
    u3_auto    car_u;                   //  driver
    c3_l       sev_l;                   //  instance numbers
  } u3_loop;

static void
_loop_born_news(u3_ovum* egg_u, u3_ovum_news new_e)
{
  u3_auto* car_u = egg_u->car_u;

  if ( u3_ovum_done == new_e ) {
    car_u->liv_o = c3y;
  }
}

/* _loop_born_bail(): %born is essential, retry failures.
*/
static void
_loop_born_bail(u3_ovum* egg_u, u3_noun lud)
{
  u3_auto* car_u = egg_u->car_u;

    u3_auto_bail_slog(egg_u, lud);
    u3_ovum_free(egg_u);

    u3l_log("loop: initialization failed\n");
    u3_pier_bail(car_u->pir_u);
}

/* _loop_io_talk(): notify %loop that we're live
*/
static void
_loop_io_talk(u3_auto* car_u)
{
  u3_loop* lop_u = (u3_loop*)car_u;

  //  XX remove [sev_l]
  //
  u3_noun wir = u3nt(c3__loop,
                     u3dc("scot", c3__uv, lop_u->sev_l),
                     u3_nul);
  u3_noun cad = u3nc(c3__born, u3_nul);

  u3_auto_peer(
    u3_auto_plan(car_u, u3_ovum_init(0, c3__l, wir, cad)),
    0,
    _loop_born_news,
    _loop_born_bail);
}

/* _loop_io_kick(): apply effects.
*/
static c3_o
_loop_io_kick(u3_auto* car_u, u3_noun wir, u3_noun cad)
{
  u3_loop* lop_u = (u3_loop*)car_u;

  c3_o ret_o = c3y;

  return ret_o;
}

/* _loop_io_exit(): terminate timer.
*/
static void
_loop_io_exit(u3_auto* car_u)
{
  u3_loop* lop_u = (u3_loop*)car_u;
  /* uv_close((uv_handle_t*)&teh_u->tim_u, (uv_close_cb)_loop_exit_cb); */
}

/* u3_loop(): initialize time timer.
*/
u3_auto*
u3_loop_io_init(u3_pier* pir_u)
{
  u3_loop* lop_u = c3_calloc(sizeof(*lop_u));

  /* uv_timer_init(u3L, &teh_u->tim_u); */

  u3_auto* car_u = &lop_u->car_u;
  car_u->nam_m = c3__loop;

  car_u->liv_o = c3n;
  car_u->io.talk_f = _loop_io_talk;
  car_u->io.kick_f = _loop_io_kick;
  car_u->io.exit_f = _loop_io_exit;

  {
    u3_noun now;
    struct timeval tim_u;
    gettimeofday(&tim_u, 0);

    now = u3_time_in_tv(&tim_u);
    lop_u->sev_l = u3r_mug(now);
    u3z(now);
  }

  return car_u;
}
