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
int	get_photos(t_photos *photos, char *name);
void	get_full_name(t_photos *photos, int id, char *full_name);
void	get_full_new_name(t_photos *photos, int id, char *full_name);
void	get_full_name_del(t_photos *photos, int id, char *full_name);
void	rename_photos_name(t_photos *photos, char *name, char *new_name);
void	rename_photos_id(t_photos *photos, int id, char *new_name);
void	del_photos_name(t_photos *photos, char *name);
void	del_photos_id(t_photos *photos, int id);
void	next_photos(t_photos *photos);
void	prev_photos(t_photos *photos);
void	create_t_gest_photos(t_photos *photos);
void	create_t_photos(t_photos *photos);
void	create_photos(t_photos *photos, char *path);
void	apply(t_photos *photos);
void	draw(t_photos *photos);
void	create_fen(t_photos *photos, int width, int height);
int	gest_event(t_photos *photos, SDL_Event event);
void	loop(t_photos *photos);

#endif
