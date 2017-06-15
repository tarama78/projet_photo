#ifndef INCL_H
#define INCL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_ttf.h>
#include "struct.h"
#include "fonc/my_getnbr.c"
#include "fonc/str_nospace.c"
#include "fonc/get_photos.c"
#include "fonc/rename_photos.c"
#include "fonc/del_photos.c"
#include "fen/change_photos.c"
#include "fonc/create_photos.c"
#include "fonc/apply.c"
#include "fen/draw.c"
#include "fen/create_fen.c"
#include "fen/close_fen.c"
#include "fen/event.c"
#include "fen/loop.c"

int	my_getnbr(char *str);
void	str_nospace(char *str);
int	get_p(t_p *p, char *name);
void	get_full_name(t_p *p, int id, char *full_name);
void	get_new_name(t_p *p, int id, char *name);
void	get_full_new_name(t_p *p, int id, char *full_name);
void	get_full_name_del(t_p *p, int id, char *full_name);
void	rename_p_name(t_p *p, char *name, char *new_name);
void	rename_p_id(t_p *p, int id, char *new_name);
void	del_p_name(t_p *p, char *name);
void	del_p_id(t_p *p, int id);
void	change_p(t_p *p);
void	next_p(t_p *p);
void	prev_p(t_p *p);
void	create_t_gest_p(t_p *p);
void	create_t_p(t_p *p);
void	create_p(t_p *p, char *path);
void	apply(t_p *p, char *retour);
void	draw(t_p *p);
void	create_fen(t_p *p, int width, int height);
void	close_fen(t_p *p);
int	gest_event(t_p *p, SDL_Event event);
int	loop(t_p *p);

#endif
