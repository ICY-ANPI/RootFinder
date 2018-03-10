struct Linear_interp : Base_interp
// Piecewise linear interpolation object. Construct with x and y vectors, then call interp for
// interpolated values.
{
	Linear_interp(VecDoub_I &xv, VecDoub_I &yv)
	: Base_interp(xv,&yv[0],2) {}
	Doub rawinterp(Int j, Doub x) {
if (xx[j]==xx[j+1]) return yy[j]; // Table is defective, but we can recover.
else return yy[j] + ((x-xx[j])/(xx[j+1]-xx[j]))*(yy[j+1]-yy[j]);
}
};