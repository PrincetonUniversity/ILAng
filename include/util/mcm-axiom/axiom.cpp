	// ----- AXIOM RF_CO_FR BEGIN -----
	ZExprVec var10_L;
	for (auto && s : m_shared_state_names) {  // forall s : m_shared_state_names
		ZExprVec var8_L;
		for (auto && r : READ_list) {  // forall r : READ_list
			if  ( ! r->Access(AccessType::READ, s) ) continue;
			ZExprVec var6_L;
			for (auto && w : WRITE_list )  { // exists w : WRITE_list
				if  ( w->name() == r->name() ) continue; 
				if  ( ! w->Access(AccessType::WRITE, s) ) continue;
				ZExprVec var4_L;
				for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
					if  ( w2->name() == w->name() ) continue; 
					if  ( w2->name() == r->name() ) continue; 
					if  ( ! w2->Access(AccessType::WRITE, s) ) continue;
					ZExpr var3 = Z3Implies( _ctx_.bool_val(true) , z3::implies( ( ( SameAddress ( *w,*w2,s,AxiomFuncHint::HINT_WRITE,AxiomFuncHint::HINT_WRITE )  && Decode ( *w2 )  )  ) , ( CO ( w2,w )  || FR ( r,w2 )  )  )  );
					var4_L.push_back( var3); }
				ZExpr var5 = Z3ForallList( var4_L);
				ZExpr var2 = Z3And( _ctx_.bool_val(true) , ( ( ( ( SameAddress ( *w,*r,s,AxiomFuncHint::HINT_WRITE,AxiomFuncHint::HINT_READ )  && SameData ( *w,*r,s,AxiomFuncHint::HINT_WRITE,AxiomFuncHint::HINT_READ )  )  && Decode ( *w )  )  && RF ( w,r )  )  && ( var5 ) )  );
				var6_L.push_back( var2); }
			ZExpr var7 = Z3ExistsList( var6_L);
			ZExpr var1 = Z3Implies( _ctx_.bool_val(true) , var7 );
			var8_L.push_back( var1); }
		ZExpr var9 = Z3ForallList( var8_L);
		var10_L.push_back( var9); }
	ZExpr var11 = Z3ForallList( var10_L);
	_constr.push_back( var11);
	// ----- AXIOM RF_CO_FR END -----
	// ----- AXIOM TSO_WriteFacetOrder BEGIN -----
	ZExprVec var12_L;
	for (auto && w : PureWrite_list) {  // forall w : PureWrite_list
		var12_L.push_back( HB ( *w,*__wfe_global( w) ) ); }
	ZExpr var13 = Z3ForallList( var12_L);
	_constr.push_back( var13);
	// ----- AXIOM TSO_WriteFacetOrder END -----
	// ----- AXIOM TSO_Store BEGIN -----
	ZExprVec var17_L;
	for (auto && w1 : WRITE_list) {  // forall w1 : WRITE_list
		ZExprVec var15_L;
		for (auto && w2 : WRITE_list) {  // forall w2 : WRITE_list
			if  ( w2->name() == w1->name() ) continue; 
			if ( !SameCore ( *w1,*w2 )  ) continue;
			ZExpr var14 = Z3Implies( _ctx_.bool_val(true) , z3::implies( ( ( SameCore ( *w1,*w2 )  && HB ( *w1,*w2 )  )  ) , HB ( *__wfe_global( w1),*__wfe_global( w2) )  )  );
			var15_L.push_back( var14); }
		ZExpr var16 = Z3ForallList( var15_L);
		var17_L.push_back( var16); }
	ZExpr var18 = Z3ForallList( var17_L);
	_constr.push_back( var18);
	// ----- AXIOM TSO_Store END -----
	// ----- AXIOM TSO_Fence BEGIN -----
	ZExprVec var21_L;
	for (auto && f : FENCE_list) {  // forall f : FENCE_list
		ZExprVec var19_L;
		for (auto && w : WRITE_list) {  // forall w : WRITE_list
			if ( !SameCore ( *w,*f )  ) continue;
			var19_L.push_back( z3::implies( ( ( SameCore ( *w,*f )  && HB ( *w,*f )  )  ) , HB ( *__wfe_global( w),*f )  ) ); }
		ZExpr var20 = Z3ForallList( var19_L);
		var21_L.push_back( var20); }
	ZExpr var22 = Z3ForallList( var21_L);
	_constr.push_back( var22);
	// ----- AXIOM TSO_Fence END -----
	// ----- AXIOM TSO_RMW BEGIN -----
	ZExprVec var23_L;
	for (auto && i : RMW_list) {  // forall i : RMW_list
		var23_L.push_back( Sync ( *i,*__wfe_global( i) ) ); }
	ZExpr var24 = Z3ForallList( var23_L);
	_constr.push_back( var24);
	// ----- AXIOM TSO_RMW END -----
 // ------------------- Functions ----------------------
z3::expr Tso::RF( const TraceStepPtr &w,const TraceStepPtr &r) {
	if (SameCore ( *w,*r )  ) return HB ( *w,*r ) ; 
	if ( !SameCore ( *w,*r )  ) return HB ( *__wfe_global( w),*r ) ; 
	return ( ( ( z3::implies( SameCore ( *w,*r )  , HB ( *w,*r )  )  ) && ( z3::implies( !( SameCore ( *w,*r )  )  , HB ( *__wfe_global( w),*r )  )  ) )  );
}

z3::expr Tso::FR( const TraceStepPtr &r,const TraceStepPtr &w) {
	if (SameCore ( *r,*w )  ) return HB ( *r,*w ) ; 
	if ( !SameCore ( *r,*w )  ) return HB ( *r,*__wfe_global( w) ) ; 
	return ( ( ( z3::implies( SameCore ( *r,*w )  , HB ( *r,*w )  )  ) && ( z3::implies( !( SameCore ( *r,*w )  )  , HB ( *r,*__wfe_global( w) )  )  ) )  );
}

z3::expr Tso::CO( const TraceStepPtr &w1,const TraceStepPtr &w2) {
	if (SameCore ( *w1,*w2 )  ) return HB ( *w1,*w2 ) ; 
	if ( !SameCore ( *w1,*w2 )  ) return HB ( *__wfe_global( w1),*__wfe_global( w2) ) ; 
	return ( ( ( z3::implies( SameCore ( *w1,*w2 )  , HB ( *w1,*w2 )  )  ) && ( z3::implies( !( SameCore ( *w1,*w2 )  )  , HB ( *__wfe_global( w1),*__wfe_global( w2) )  )  ) )  );
}
