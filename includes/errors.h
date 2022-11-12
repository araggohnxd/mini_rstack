/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:04:44 by maolivei          #+#    #+#             */
/*   Updated: 2022/11/12 16:11:16 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/************************************ ERROR ***********************************/

# define ERROR        "\e[0;31mError\e[0m\n"
# define USAGE        "Usage: ./miniRT <map file>.rt"
# define ERR_MANY_ARG "Too many arguments"
# define ERR_FEW_ARG  "Too few arguments"

/************************************* MLX ************************************/

# define ERR_MLX_DISPLAY    "Unable to create MLX display"
# define ERR_MLX_WINDOW     "Unable to create MLX window"
# define ERR_MLX_IMAGE      "Unable to create MLX image"
# define ERR_MLX_IMAGE_DATA "Unable to retrieve MLX image's data"

/*********************************** RT FILE **********************************/

# define ERR_BAD_ID    "Invalid identifier in '.rt' file"
# define ERR_BAD_EXT   "Scene description file must have '.rt' extension"
# define ERR_OPEN_FAIL "Could not open '.rt' file"

/*********************************** AMBIENT **********************************/

# define ERR_AMB_MALLOC_FAIL "Unable to allocate memory for ambient"
# define ERR_AMB_ALREADY_SET "Ambient lighting must be set only once"
# define ERR_AMB_BAD_CONFIGS "Invalid ambient configuration"
# define ERR_AMB_RATIO_VALUE "Invalid ambient lighting ratio value"
# define ERR_AMB_RATIO_RANGE "Ambient lighting ratio must be between 0 and 1"
# define ERR_AMB_COLOR_SETTN "Invalid ambient color settings"
# define ERR_AMB_COLOR_VALUE "Invalid ambient color value"
# define ERR_AMB_COLOR_RANGE "Ambient color channels must be between 0 and 255"

/*********************************** CAMERA ***********************************/

# define ERR_CAM_MALLOC_FAIL "Unable to allocate memory for camera"
# define ERR_CAM_ALREADY_SET "Camera must be set only once"
# define ERR_CAM_BAD_CONFIGS "Invalid camera configuration"
# define ERR_CAM_VIEWP_SETTN "Invalid camera view point settings"
# define ERR_CAM_VIEWP_VALUE "Invalid camera view point value"
# define ERR_CAM_OVECT_SETTN "Invalid camera orientation vector settings"
# define ERR_CAM_OVECT_VALUE "Invalid camera orientation vector value"
# define ERR_CAM_OVECT_RANGE "Camera orietation values must be between -1 and 1"
# define ERR_CAM_FIELD_VALUE "Invalid camera field of view value"
# define ERR_CAM_FIELD_RANGE "Camera field of view must be between 0 and 180"
# define ERR_CAM_NOT_NORMALIZED "Camera orientation vector is not normalized"

/************************************ LIGHT ***********************************/

# define ERR_LGT_LINKED_LIST "Unable to allocate memory for light list node"
# define ERR_LGT_MALLOC_FAIL "Unable to allocate memory for light"
# define ERR_LGT_BAD_CONFIGS "Invalid light configuration"
# define ERR_LGT_POINT_SETTN "Invalid light point settings"
# define ERR_LGT_POINT_VALUE "Invalid light point value"
# define ERR_LGT_BRGHT_VALUE "Invalid light brightness value"
# define ERR_LGT_BRGHT_RANGE "Light brightness must be between 0 and 1"
# define ERR_LGT_COLOR_SETTN "Invalid light color settings"
# define ERR_LGT_COLOR_VALUE "Invalid light color value"
# define ERR_LGT_COLOR_RANGE "Light color channels must be between 0 and 255"

/******************************** GENERAL SHAPES ******************************/

# define ERR_SHP_LINKED_LIST "Unable to allocate memory for cylinder list node"
# define ERR_SHP_OVECT_SETTN "Invalid shape orientation vector settings"
# define ERR_SHP_OVECT_VALUE "Invalid shape orientation vector value"
# define ERR_SHP_OVECT_RANGE "Shape orientation values must be between -1 and 1"
# define ERR_SHP_COLOR_SETTN "Invalid shape color settings"
# define ERR_SHP_COLOR_VALUE "Invalid shape color value"
# define ERR_SHP_COLOR_RANGE "Shape color channels must be between 0 and 255"
# define ERR_SHP_NOT_NORMALIZED "Shape orientation vector is not normalized"

/************************************ SPHERE **********************************/

# define ERR_SPH_MALLOC_FAIL "Unable to allocate memory for sphere"
# define ERR_SPH_BAD_CONFIGS "Invalid sphere configuration"
# define ERR_SPH_CENTR_SETTN "Invalid sphere center coordinates settings"
# define ERR_SPH_CENTR_VALUE "Invalid sphere center coordinates value"
# define ERR_SPH_DMTER_VALUE "Invalid sphere diameter value"
# define ERR_SPH_DMTER_RANGE "Sphere diameter value must be greater than 0"

/************************************ PLANE ***********************************/

# define ERR_PLN_MALLOC_FAIL "Unable to allocate memory for plane"
# define ERR_PLN_BAD_CONFIGS "Invalid plane configuration"
# define ERR_PLN_COORD_SETTN "Invalid plane coordinates settings"
# define ERR_PLN_COORD_VALUE "Invalid plane coordinates value"

/*********************************** CYLINDER *********************************/

# define ERR_CYL_MALLOC_FAIL  "Unable to allocate memory for cylinder"
# define ERR_CYL_BAD_CONFIGS  "Invalid cylinder configuration"
# define ERR_CYL_COORD_SETTN  "Invalid cylinder coordinates settings"
# define ERR_CYL_COORD_VALUE  "Invalid cylinder coordinates value"
# define ERR_CYL_DMTER_VALUE  "Invalid cylinder diameter value"
# define ERR_CYL_DMTER_RANGE  "Cylinder diameter value must be greater than 0"
# define ERR_CYL_HEIGHT_VALUE "Invalid cylinder height value"
# define ERR_CYL_HEIGHT_RANGE "Cylinder height value must be greater than 0"

/************************************ CONE ************************************/

# define ERR_CON_MALLOC_FAIL  "Unable to allocate memory for cone"
# define ERR_CON_BAD_CONFIGS  "Invalid cone configuration"
# define ERR_CON_COORD_SETTN  "Invalid cone coordinates settings"
# define ERR_CON_COORD_VALUE  "Invalid cone coordinates value"
# define ERR_CON_DMTER_VALUE  "Invalid cone diameter value"
# define ERR_CON_DMTER_RANGE  "Cone diameter value must be greater than 0"
# define ERR_CON_HEIGHT_VALUE "Invalid cone height value"
# define ERR_CON_HEIGHT_RANGE "Cone height value must be greater than 0"

/*********************************** PATTERN **********************************/

# define ERR_PAT_INVALID_FEAT  "Invalid shape feature"
# define ERR_PAT_CHECKER_SETTN "Invalid checkerboard color settings"
# define ERR_PAT_CHECKER_VALUE "Invalid checkerboard color value"
# define ERR_PAT_CHECKER_RANGE "Checkerboard \
color channels must be between 0 and 255"
# define ERR_PAT_CHECKER_COLOR "Checkerboard requires a color feature"
# define ERR_PAT_BUMPMAP_NOXPM "Bump map requires a path to a '.xpm' file"
# define ERR_PAT_BUMPMAP_NOEXT "Bump map file must have '.xpm' extension"
# define ERR_PAT_BUMPMAP_IMAGE "Unable to create bump map image"

/********************************* MISSING INFO *******************************/

# define ERR_UNDEF_AMB "Undefined ambient"
# define ERR_UNDEF_CAM "Undefined camera"
# define ERR_UNDEF_LGT "At least one light spot is required"
# define ERR_UNDEF_OBJ "At least one object is required"

#endif /* ERRORS_H */
