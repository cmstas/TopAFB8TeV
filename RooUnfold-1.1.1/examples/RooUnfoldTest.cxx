//=====================================================================-*-C++-*-
// File and Version Information:
//      $Id: RooUnfoldTest.cxx,v 1.1 2012/05/24 22:03:39 linacre Exp $
//
// Description:
//      Tests RooUnfold package using toy MC generated according to PDFs
//      defined in RooUnfoldTestPdf.icc or RooUnfoldTestPdfRooFit.icc.
//      This is the main program. The actual tests are performed using the
//      RooUnfoldTestHarness class.
//
// Author: Tim Adye <T.J.Adye@rl.ac.uk>
//
//==============================================================================

#include "RooUnfoldTestHarness.h"

RooUnfoldTestHarness* test= 0;

//==============================================================================
// Routine to run with parameters specified as a string
//==============================================================================

void RooUnfoldTest (const char* args= "")
{
#ifdef __CINT__
  if (!TClass::GetDict("RooUnfold")) gSystem->Load("libRooUnfold");
#endif
// If run interactively, remove canvas and all histograms that might have been
// created with a previous invocation.
  delete test; test= 0;
  gDirectory->Clear();

  test= new RooUnfoldTestHarness ("RooUnfoldTest", args);
  test->Run();
}

#ifndef __CINT__

//==============================================================================
// Main program when run stand-alone
//==============================================================================

int main (int argc, char** argv) {
  RooUnfoldTestHarness maintest ("RooUnfoldTest", argc, argv);
  return maintest.Run();
}

#endif
