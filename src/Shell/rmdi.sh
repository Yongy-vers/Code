rmdi(){
	h='
################### rmdi #######################
# Usage:
#	rmdir dirname
#	
#	Parameters:
#		dirname : Directory to remove
#	
#		-h : show the page
###############################################
	'
	[[ $1 = -h ]] && { echo "$h" > /dev/stderr; return 1; }
	if [ ! -d $1]
	then
		echo "$1 is not a directory"
	else
		cd $1
		rm -rf .* *
		cd ..
	fi
}
