/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:10:44 by pedromar          #+#    #+#             */
/*   Updated: 2024/05/20 16:23:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	points_axis(t_render *r)
{
	r->n_point = 9;
	r->p = mallox(sizeof(t_point) * r->n_point);
	r->p[0].r = ft_vec4(0.0f, 0.0f, 0.0f, 1.0);
	r->p[0].color = get_rgba(0x00FF0000);
	r->p[1].r = ft_vec4(1.0f, 0.0f, 0.0f, 1.0);
	r->p[1].color = get_rgba(0x00FF0000);
	r->p[2].r = ft_vec4(0.0f, 0.0f, 0.0f, 1.0);
	r->p[2].color = get_rgba(0x00FF0000);
	r->p[3].r = ft_vec4(0.0f, 0.0f, 0.0f, 1.0);
	r->p[3].color = get_rgba(0x0000FF00);
	r->p[4].r = ft_vec4(0.0f, 1.0f, 0.0f, 1.0);
	r->p[4].color = get_rgba(0x0000FF00);
	r->p[5].r = ft_vec4(0.0f, 0.0f, 0.0f, 1.0);
	r->p[5].color = get_rgba(0x0000FF00);
	r->p[6].r = ft_vec4(0.0f, 0.0f, 0.0f, 1.0);
	r->p[6].color = get_rgba(0x000000FF);
	r->p[7].r = ft_vec4(0.0f, 0.0f, 1.0f, 1.0);
	r->p[7].color = get_rgba(0x000000FF);
	r->p[8].r = ft_vec4(0.0f, 0.0f, 0.0f, 1.0);
	r->p[8].color = get_rgba(0x000000FF);
}

void	points_box(t_render *r)
{
	r->n_point = 35;
	r->p = mallox(sizeof(t_point) * r->n_point);
	r->p[0].r = ft_vec4(1.0, 1.0, 1.0, 1.0f);
	r->p[0].color = get_rgba(0x00FFFFFF);
	r->p[1].r = ft_vec4(1.0, 1.0, 1.0, 1.0f);
	r->p[1].color = get_rgba(0x00FFFFFF);
	r->p[2].r = ft_vec4(1.0, 1.0, -1.0, 1.0f);
	r->p[2].color = get_rgba(0x00FFFFFF);
	r->p[3].r = ft_vec4(1.0, 1.0, -1.0, 1.0f);
	r->p[3].color = get_rgba(0x00FFFFFF);
	r->p[4].r = ft_vec4(1.0, -1.0, -1.0, 1.0f);
	r->p[4].color = get_rgba(0x00FFFFFF);
	r->p[5].r = ft_vec4(1.0, -1.0, -1.0, 1.0f);
	r->p[5].color = get_rgba(0x00FFFFFF);
	r->p[6].r = ft_vec4(1.0, -1.0, 1.0, 1.0f);
	r->p[6].color = get_rgba(0x00FFFFFF);
	r->p[7].r = ft_vec4(1.0, -1.0, 1.0, 1.0f);
	r->p[7].color = get_rgba(0x00FFFFFF);
	r->p[8].r = ft_vec4(1.0, 1.0, 1.0, 1.0f);
	r->p[8].color = get_rgba(0x00FFFFFF);
	r->p[9].r = ft_vec4(1.0, 1.0, 1.0, 1.0f);
	r->p[9].color = get_rgba(0x00FFFFFF);
	r->p[10].r = ft_vec4(-1.0, 1.0, 1.0, 1.0f);
	r->p[10].color = get_rgba(0x00FFFFFF);
	r->p[11].r = ft_vec4(-1.0, 1.0, 1.0, 1.0f);
	r->p[11].color = get_rgba(0x00FFFFFF);
	r->p[12].r = ft_vec4(-1.0, 1.0, -1.0, 1.0f);
	r->p[12].color = get_rgba(0x00FFFFFF);
	r->p[13].r = ft_vec4(-1.0, 1.0, -1.0, 1.0f);
	r->p[13].color = get_rgba(0x00FFFFFF);
	r->p[14].r = ft_vec4(-1.0, 1.0, -1.0, 1.0f);
	r->p[14].color = get_rgba(0x00FFFFFF);
	r->p[15].r = ft_vec4(-1.0, 1.0, -1.0, 1.0f);
	r->p[15].color = get_rgba(0x00FFFFFF);
	r->p[16].r = ft_vec4(1.0, 1.0, -1.0, 1.0f);
	r->p[16].color = get_rgba(0x00FFFFFF);
	r->p[17].r = ft_vec4(1.0, 1.0, -1.0, 1.0f);
	r->p[17].color = get_rgba(0x00FFFFFF);
	r->p[18].r = ft_vec4(1.0, 1.0, 1.0, 1.0f);
	r->p[18].color = get_rgba(0x00FFFFFF);
	r->p[19].r = ft_vec4(1.0, 1.0, 1.0, 1.0f);
	r->p[19].color = get_rgba(0x00FFFFFF);
	r->p[20].r = ft_vec4(-1.0, 1.0, 1.0, 1.0f);
	r->p[20].color = get_rgba(0x00FFFFFF);
	r->p[21].r = ft_vec4(-1.0, 1.0, 1.0, 1.0f);
	r->p[21].color = get_rgba(0x00FFFFFF);
	r->p[22].r = ft_vec4(-1.0, -1.0, 1.0, 1.0f);
	r->p[22].color = get_rgba(0x00FFFFFF);
	r->p[23].r = ft_vec4(-1.0, -1.0, 1.0, 1.0f);
	r->p[23].color = get_rgba(0x00FFFFFF);
	r->p[24].r = ft_vec4(-1.0, -1.0, -1.0, 1.0f);
	r->p[24].color = get_rgba(0x00FFFFFF);
	r->p[25].r = ft_vec4(-1.0, -1.0, -1.0, 1.0f);
	r->p[25].color = get_rgba(0x00FFFFFF);
	r->p[26].r = ft_vec4(-1.0, 1.0, -1.0, 1.0f);
	r->p[26].color = get_rgba(0x00FFFFFF);
	r->p[27].r = ft_vec4(-1.0, 1.0, -1.0, 1.0f);
	r->p[27].color = get_rgba(0x00FFFFFF);
	r->p[28].r = ft_vec4(-1.0, -1.0, -1.0, 1.0f);
	r->p[28].color = get_rgba(0x00FFFFFF);
	r->p[29].r = ft_vec4(-1.0, -1.0, -1.0, 1.0f);
	r->p[29].color = get_rgba(0x00FFFFFF);
	r->p[30].r = ft_vec4(1.0, -1.0, -1.0, 1.0f);
	r->p[30].color = get_rgba(0x00FFFFFF);
	r->p[31].r = ft_vec4(1.0, -1.0, -1.0, 1.0f);
	r->p[31].color = get_rgba(0x00FFFFFF);
	r->p[32].r = ft_vec4(1.0, -1.0, 1.0, 1.0f);
	r->p[32].color = get_rgba(0x00FFFFFF);
	r->p[33].r = ft_vec4(1.0, -1.0, 1.0, 1.0f);
	r->p[33].color = get_rgba(0x00FFFFFF);
	r->p[34].r = ft_vec4(-1.0, -1.0, 1.0, 1.0f);
	r->p[34].color = get_rgba(0x00FFFFFF);
}


// TODO: otras primiticas