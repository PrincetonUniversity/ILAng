	// ----- AXIOM RF_CO_FR BEGIN -----
	ZExprVec var7_L;
	for (auto && r : READ_list) {  // forall r : READ_list
		ZExprVec var5_L;
		for (auto && w : WRITE_list )  { // exists
			if  ( w.name() == r.name() ) continue; 
			ZExprVec var3_L;
			for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
				if  ( w2.name() == w.name() ) continue; 
				var2 = Z3Implies( ctx_.bool_val(true) , z3::implies( ( ( SameAddress ( w , w2 )  && Decode ( w2 )  )  ) , ( CO ( w2 , w )  || FR ( r , w2 )  )  )  );
				var3_L.push_back( var2); }
			var4 = Z3ForallList( var3_L);
			var1 = Z3And( ctx_.bool_val(true) , ( ( ( ( SameAddress ( w , r )  && SameData ( w , r )  )  && Decode ( w )  )  && RF ( w , r )  )  && ( var4 ) )  );
			var5_L.push_back( var1); }
		var6 = Z3ExistsList( var5_L);
		var7_L.push_back( var6); }
	var8 = Z3ForallList( var7_L);
	_constr.push_back( var8);
	// ----- AXIOM RF_CO_FR END -----
	// ----- AXIOM TSO_WriteFacetOrder BEGIN -----
	ZExprVec var9_L;
	for (auto && w : PureWrite_list) {  // forall w : PureWrite_list
		var9_L.push_back( HB ( w , __wfe_global( w) ) ); }
	var10 = Z3ForallList( var9_L);
	_constr.push_back( var10);
	// ----- AXIOM TSO_WriteFacetOrder END -----
	// ----- AXIOM TSO_Store BEGIN -----
	ZExprVec var14_L;
	for (auto && w1 : WRITE_list) {  // forall w1 : WRITE_list
		ZExprVec var12_L;
		for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
			if  ( w2.name() == w1.name() ) continue; 
			var11 = Z3Implies( ctx_.bool_val(true) , z3::implies( PO ( w1 , w2 )  , HB ( __wfe_global( w1) , __wfe_global( w2) )  )  );
			var12_L.push_back( var11); }
		var13 = Z3ForallList( var12_L);
		var14_L.push_back( var13); }
	var15 = Z3ForallList( var14_L);
	_constr.push_back( var15);
	// ----- AXIOM TSO_Store END -----
	// ----- AXIOM TSO_Fence BEGIN -----
	ZExprVec var18_L;
	for (auto && f : FENCE_list) {  // forall f : FENCE_list
		ZExprVec var16_L;
		for (auto && w : WRITE_list) {  // forall w : WRITE_list
			var16_L.push_back( z3::implies( PO ( w , f )  , HB ( __wfe_global( w) , f )  ) ); }
		var17 = Z3ForallList( var16_L);
		var18_L.push_back( var17); }
	var19 = Z3ForallList( var18_L);
	_constr.push_back( var19);
	// ----- AXIOM TSO_Fence END -----
	// ----- AXIOM TSO_RMW BEGIN -----
	ZExprVec var20_L;
	for (auto && i : RMW_list) {  // forall i : RMW_list
		var20_L.push_back( Sync ( i , __wfe_global( i) ) ); }
	var21 = Z3ForallList( var20_L);
	_constr.push_back( var21);
	// ----- AXIOM TSO_RMW END -----