/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaillie <rcaillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:43:02 by rcaillie          #+#    #+#             */
/*   Updated: 2024/11/25 15:02:55 by rcaillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_MSG_H
# define ERRORS_MSG_H

# define ERR_MALLOC "Malloc failed"
# define ERR_OPEN "Open failed"
# define ERR_CLOSE "Close failed"
# define ERR_READ "Read failed"
# define ERR_WRITE "Write failed"
# define ERR_MAP "Map is invalid"
# define ERR_MAP_CHAR "Map contains invalid char"
# define ERR_MAP_WALL "Map is not surrounded by walls"
# define ERR_MAP_PLAYER "Map must contain only one player"
# define ERR_MAP_COLLECT "Map must contain at least one coins"
# define ERR_MAP_EXIT "Map must contain at least one exit"
# define ERR_IMG_LOAD "Failed to convert texture to image"
# define ERR_TX_LOAD "Failed to load texture"
# define ERR_DISPLAY "Failed to draw the image to the window."

#endif