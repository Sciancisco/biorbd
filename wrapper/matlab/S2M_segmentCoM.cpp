

void S2M_segmentCOM( int nlhs, mxArray *plhs[],
				int nrhs, const mxArray*prhs[] ){
	// Verifier les arguments d'entrée
	checkNombreInputParametres(nrhs, 3, 4, "3 arguments are required (+1 optional) where the 2nd is the handler on the model, 3rd is the Q and 4th is the index of body segment");
	
	// Recevoir le model
	s2mMusculoSkeletalModel * model = convertMat2Ptr<s2mMusculoSkeletalModel>(prhs[1]);
    unsigned int nQ = model->nbQ(); /* Get the number of DoF */
	
	// Recevoir Q
    s2mGenCoord Q = *getParameterQ(prhs, 2, nQ).begin();
	// Recevoir le numéro du segment (optionnel)
	int i(0);
	if (nrhs==4)
		i = getInteger(prhs, 3);
	i -= 1; // -1 car le segment 0 est numéroté 1 sous matlab
		
	// Trouver la position du CoM
	if (i==-1){
                std::vector<RigidBodyDynamics::Math::Vector3d> COM = model->CoMbySegment(Q,true);
		/* Create a matrix for the return argument */
		plhs[0] = mxCreateDoubleMatrix( 3, model->nbBone(), mxREAL);
		// Remplir l'output
		double *tp = mxGetPr(plhs[0]);
		for (unsigned int j=0; j<model->nbBone(); ++j)
			for (unsigned int k=0; k<3; ++k)
				tp[3*j+k] = COM[j][k]; // Transférer le tout dans un tableau de sortie
	}
	else{
                RigidBodyDynamics::Math::Vector3d COM = model->CoMbySegment(Q,i,true);
		
		/* Create a matrix for the return argument */
		plhs[0] = mxCreateDoubleMatrix( 3, 1, mxREAL);
		// Remplir l'output
		double *tp = mxGetPr(plhs[0]);
		for (unsigned int k=0; k<3; ++k)
			tp[k] = COM[k]; // Transférer le tout dans un tableau de sortie
	}

	return;
}
