#ifndef TrueTrackCritAnalyser_h
#define TrueTrackCritAnalyser_h

#include <string>

#include "marlin/Processor.h"
#include "lcio.h"
#include "EVENT/TrackerHit.h"
#include "EVENT/Track.h"
#include "EVENT/LCRelation.h"
#include "MarlinTrk/IMarlinTrkSystem.h"

#include "KiTrack/Segment.h"
#include "Criteria/ICriterion.h"

#include "ILDImpl/SectorSystemFTD.h"

using namespace lcio ;
using namespace marlin ;
using namespace KiTrackMarlin;





/**  Processor to analyse what kind of criteria the the true tracks fulfill.
 * 
 * 
 *  <h4>Input - Prerequisites</h4>
 *  The true tracks to be analysed
 *
 *  <h4>Output</h4> 
 *  A root file
 * 
 * @param MCTrueTrackRelCollectionName The true track <-> MCP relations in the FTDs
 * 
 * @author R. Glattauer HEPHY, Wien
 *
 */



class TrueTrackCritAnalyser : public Processor {
   
public:
   
   virtual Processor*  newProcessor() { return new TrueTrackCritAnalyser ; }
   
   
   TrueTrackCritAnalyser() ;
   
   /** Called at the begin of the job before anything is read.
    * Use to initialize the processor, e.g. book histograms.
    */
   virtual void init() ;
   
   /** Called for every run.
    */
   virtual void processRunHeader( LCRunHeader* run ) ;
   
   /** Called for every event - the working horse.
    */
   virtual void processEvent( LCEvent * evt ) ; 
   
   
   virtual void check( LCEvent * evt ) ; 
   
   
   /** Called after data processing for clean up.
    */
   virtual void end() ;
   
   
   
   
protected:
   
   
   
   /** Input collection name.
    */
   std::string _FTDTrueTracks;
   
   
   
   int _nRun ;
   int _nEvt ;
   
   
   double _Bz; //B field in z direction
   
   std::string _rootFileName;
   std::string _treeName2;
   std::string _treeName3;
   std::string _treeName4;
   std::string _treeNameKalman;

   std::string _colNameMCTrueTracksRel;
   
   std::vector <ICriterion*> _crits2;
   std::vector <ICriterion*> _crits3;
   std::vector <ICriterion*> _crits4;

   
   
   bool _MSOn ;
   bool _ElossOn ;
   bool _SmoothOn ;
   
   
   double _ptMin;
   double _distToIPMax;
   double _chi2ProbCut;
   int _nHitsMin;
   double _overlappingHitsDistMax;
   bool _writeNewRootFile;
   
   const SectorSystemFTD* _sectorSystemFTD;
   
   MarlinTrk::IMarlinTrkSystem* _trkSystem;
   
   
} ;

#endif



