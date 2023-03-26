# Raytracing non-RT

For the different diffuse methods, the random_in_unit_sphere uses any point in a sphere around the normal unit vector point.

![Unit sphere diffuse](https://github.com/grantsadie/Raytracing-non-RT/blob/master/random_in_unit_sphere_diffuse.png)

The random_unit_vector diffuse method uses points ON the sphere surface (unit vector). This way, we get points with direction closer to the normal.

![Unit vector diffuse](https://github.com/grantsadie/Raytracing-non-RT/blob/master/random_unit_vector_diffuse.png)

The random_in_hemisphere will only use points pointing in the same hemisphere as the normal, or in other words, rejecting all points that are over 90 degrees in difference from the normal.

![Unit vector diffuse](https://github.com/grantsadie/Raytracing-non-RT/blob/master/random_in_hemisphere_diffuse.png)

