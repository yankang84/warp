#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "datadef.h"
/**
 * \brief primitive class
 */

class primitive
{	
	public:
	/**
	 * box default constuctor. sets all coordinate extrema to zero, sets location
	 * to origin, sets type and material to zero.
	 */ 
	 primitive();
	/**
	 * box valued constructor. sets coordinate extrema to input values, sets 
	 * location to input values, sets material to input material, sets type to 
	 * input type, creates a wtransform, adds cell number and material to the 
	 * wtransform, adds the transform to the transform list.
	 *
	 * @param[in] ptype   - primitive type
	 * @param[in] cellmat - cell material
	 * @param[in] mins    - object minima
	 * @param[in] maxs    - object maxima
	 * @param[in] locs    - object center points
	 */
	 primitive(int,unsigned,std::vector<float>, std::vector<float>, std::vector<float>);
	/**
	 * primitive destructor
	 */ 
	~primitive();
	/**
	 * adds a "default" transform - all coordinate values and angles are zero.
	 * \returns index of the added transform
	 */ 
	unsigned add_transform();
	/**
	 * adds a transform, defaults to primitive material. cell number is set to input value, 
	 * coordinates are set to input values, angles are set to input values.
	 *
	 * @param[in] cellnum     - cell number
	 * @param[in] dx,dy,dz    - transform coordinates
	 * @param[in] theta, phi  - transform azimuthal and polar angles, respectively
	 * \returns index of the added transform
	 */
	unsigned add_transform(unsigned,float,float,float,float,float);  //defaults to primitive material
	/**
	 * adds a transform. cell number is set to input value, material is set to input material, 
	 * coordinates are set to input values, angles are set to input values.
	 *
	 * @param[in] cellnum     - cell number
	 * @param[in] cellmat     - cell material
	 * @param[in] dx          - displacement in x 
	 * @param[in] dy          - displacement in y 
	 * @param[in] dz          - displacement in z 
	 * @param[in] theta       - transform azimuthal and polar angles
	 * @param[in] phi         - transform azimuthal and polar anglesrespectively
	 * \returns index of the added transform
	 */
	unsigned add_transform(unsigned,unsigned,float,float,float,float,float); //set own material
	/**
	 * prints primitive ID, coordinate extrema, location, type and material. for each 
	 * transform, prints the number, cell number, cell material, transform coordinates, 
	 * and transform angles.
	 */
	void print_transform();
	/**
	 * prints out the properties of the input transform.
	 *
	 * @param[in] tnum          - transform number
	 */ 
	void print_transform(int);
	/**
	 * creates a hexagonal array of elements.
	 *
	 * @param[in] n               - edge length
	 * @param[in] x               - x dispacement coordinates
	 * @param[in] y               - y dispacement coordinates
	 * @param[in] PD_ratio        - pitch-to-diameter ratio
	 * @param[in] starting_index  - starting index
	 */ 
	void make_hex_array(int,float,float,float,unsigned);

	//
	float       min[3];						/**< coordinate minima array */
	float       max[3];						/**< coordinate maxima array */
	float       location[3];				/**< coordinate location array */
	static int  num_primitives;				/**< number of primitives */
	int	    	type;      					/**< primitive type: 0 = box, 1 = cylinder, 2 = hexagon, 3 = sphere */
	int 	    primitive_id;				/**< primitive ID number */
	int         n_transforms;				/**< number of  transforms */
	int         material;					/**< material number */
	std::vector<wtransform>   transforms; 	/**< transform vector */
};

#endif
