
  enum constants {
    kAir = 1,
    kVac = 3,
    kCeramic = 4,
    kGlass = 6,
    kOpAir = 7,
    kAl = 15,
    kOpGlass = 16,
    kOptAl = 17,
    kOptBlack = 18,
    kOpGlassCathode = 19,
    kSensAir = 22
  }; // materials

  Int_t mIdSens1;            // Sensitive volume  in T0
  //TGraph* mPMTeff = nullptr; // pmt registration effeicincy


  // Optical properties to be extracted from file
  std::vector<Double_t> mPhotonEnergyD;
  std::vector<Double_t> mAbsorptionLength;
  std::vector<Double_t> mRefractionIndex;
  std::vector<Double_t> mQuantumEfficiency;

  // Optical properties to be set to constants
  std::vector<Double_t> mEfficAll;
  std::vector<Double_t> mRindexAir;
  std::vector<Double_t> mAbsorAir;
  std::vector<Double_t> mRindexCathodeNext;
  std::vector<Double_t> mAbsorbCathodeNext;
  std::vector<Double_t> mEfficMet;
  std::vector<Double_t> mReflMet;
  std::vector<Double_t> mRindexMet;
  std::vector<Double_t> mReflBlackPaper;
  std::vector<Double_t> mAbsBlackPaper;
  std::vector<Double_t> mEffBlackPaper;
  std::vector<Double_t> mReflFrontWindow;

  /// Container for data points
  std::vector<o2::ft0::HitType>* mHits = nullptr;

  /// Define the sensitive volumes of the geometry
 // void defineSensitiveVolumes();

// Define the aluminium frame for the detector
 /* TGeoVolume* constructFrameGeometry();
  std::string frame1CompositeShapeBoolean();
  std::string frame2CompositeShapeBoolean();
  std::string frameCompositeShapeBoolean();
  std::string plateGroupCompositeShapeBoolean();
  std::string opticalFiberPlateCompositeShapeBoolean1();
  std::string opticalFiberPlateCompositeShapeBoolean2();
  std::string pmtCornerCompositeShapeBoolean();
  std::string pmtCompositeShapeBoolean();
  std::string plateBoxCompositeShapeBoolean();
  void defineTransformations();
  void defineQuartzRadiatorTransformations();
  void definePmtTransformations();
  void definePlateTransformations();
  void defineFrameTransformations();
*/

  // define some error to avoid overlaps
  static constexpr Double_t sEps = 0.025;

  // offset found to potentially remove overlaps
  static constexpr Double_t sXoffset = 0.3027999999999995;
  static constexpr Double_t sYoffset = -0.6570999999999998;

  // frame 1 has a longer side horizontal
  static constexpr Double_t sFrame1X = 21.500;
  static constexpr Double_t sFrame1Y = 13.705;
  static constexpr Double_t sFrame1PosX = 7.9278 - sXoffset;
  static constexpr Double_t sFrame1PosY = 9.2454 - sYoffset;
  // static constexpr Double_t sFrame1PosX = 7.9278 - .1269;
  // static constexpr Double_t sFrame1PosY = 9.2454 + .2769*2;
  static constexpr Double_t sRect1X = 15;
  static constexpr Double_t sRect1Y = 1.33;
  static constexpr Double_t sRect2X = 2.9;
  static constexpr Double_t sRect2Y = 12.2;
  static constexpr Double_t sRect3X = 1.57;
  static constexpr Double_t sRect3Y = .175;
  static constexpr Double_t sRect4X = 5.65;
  static constexpr Double_t sRect4Y = 1.075;

  // frame 2 has a longer side vertical
  static constexpr Double_t sFrame2X = 13.930;
  static constexpr Double_t sFrame2Y = 21.475;
  static constexpr Double_t sFrame2PosX = 10.1428 - sXoffset;
  static constexpr Double_t sFrame2PosY = -8.3446 - sYoffset;
  // static constexpr Double_t sFrame2PosX = 10.1428 - .2769 - .15;
  // static constexpr Double_t sFrame2PosY = -8.3446 + .4812;
  static constexpr Double_t sRect5X = 1.33;
  static constexpr Double_t sRect5Y = 12.1;
  static constexpr Double_t sRect6X = .83;
  static constexpr Double_t sRect6Y = 3.0;
  static constexpr Double_t sRect7X = 13.1;
  static constexpr Double_t sRect7Y = 3.0;
  static constexpr Double_t sRect8X = 1.425;
  static constexpr Double_t sRect8Y = 5.5;

  // for subtracting extra aluminum

  static constexpr Double_t sFrame1ExtraX1 = 3.25;
  static constexpr Double_t sFrame1ExtraX2 = 9.3;
  static constexpr Double_t sFrame1ExtraX3 = 10.75;
  static constexpr Double_t sFrame1ExtraX4 = -7.925;
  static constexpr Double_t sFrame2ExtraX1 = 6.965;
  static constexpr Double_t sFrame2ExtraX2 = 6.965;
  static constexpr Double_t sFrame2ExtraX3 = 6.965;
  static constexpr Double_t sFrame2ExtraX4 = -5.89;


  static constexpr Double_t sFrame1ExtraY1 = 6.1875;
  static constexpr Double_t sFrame1ExtraY2 = -0.5775;
  static constexpr Double_t sFrame1ExtraY3 = -6.8525;
  static constexpr Double_t sFrame1ExtraY4 = -6.44;
  static constexpr Double_t sFrame2ExtraY1 = 4.3625;
  static constexpr Double_t sFrame2ExtraY2 = -10.7375;
  static constexpr Double_t sFrame2ExtraY3 = -10.7375;
  static constexpr Double_t sFrame2ExtraY4 = 5.1125;


  // both frame boxes are the same height
  static constexpr Double_t sFrameZ = 5.700;
  static constexpr Double_t sMountZ = 1.5;

  // PMT dimensions
  static constexpr Double_t sPmtSide = 5.950;
  static constexpr Double_t sPmtZ = 3.750;

  // quartz radiator dimensions
  static constexpr Double_t sQuartzRadiatorSide = 5.350;
  static constexpr Double_t sQuartzRadiatorZ = 1.950;

  // for the rounded corners
  static constexpr Double_t sCornerRadius = .300;

  // bottom plates on the frame
  static constexpr Double_t sPlateSide = 6.000;
  static constexpr Double_t sBasicPlateZ = 0.200;
  static constexpr Double_t sCablePlateZ  = 0.500;
  static constexpr Double_t sFiberHeadX = 0.675 * 2;
  static constexpr Double_t sFiberHeadY = 0.275 * 2;

  // plate transformations
  static constexpr Double_t sOpticalFiberPlateZ = 0.35;
  static constexpr Double_t sPlateSpacing = 6.100;
  static constexpr Double_t sPlateDisplacementDeltaY = 1.33;
  static constexpr Double_t sPlateDisplacementX = sPlateSpacing + 0.3028;
  static constexpr Double_t sPlateDisplacementY = 12.8789 - sPlateDisplacementDeltaY;
  static constexpr Double_t sPlateGroupZ = -sFrameZ / 2 - sOpticalFiberPlateZ;

  // quartz & PMT transformations
  static constexpr Double_t sQuartzHeight = -sFrameZ / 2 + sQuartzRadiatorZ / 2;
  static constexpr Double_t sPmtHeight = sFrameZ / 2 - sPmtZ / 2;
  static constexpr Double_t sPmtCornerTubePos = -.15;
  static constexpr Double_t sPmtCornerPos = 2.825;
  static constexpr Double_t sEdgeCornerPos[2] = {-6.515, -.515};
  static constexpr Double_t sQuartzFrameOffsetX = -1.525;
  static constexpr Double_t sPos1X[3] = {sQuartzFrameOffsetX - sPlateSpacing, sQuartzFrameOffsetX, sQuartzFrameOffsetX + sPlateSpacing};
  static constexpr Double_t sPos1Y[4] = {3.6275, -2.4725, 2.2975, -3.8025};
  static constexpr Double_t sPos2X[4] = {3.69, -2.410, 2.360, -3.740};
  static constexpr Double_t sPos2Y[3] = {7.6875, 1.5875, -4.5125};



  // constants from Geometry.h
  static constexpr int NCellsA = 24;          // number of radiatiors on A side
  static constexpr int NCellsC = 28;          // number of radiatiors on C side
  static constexpr float ZdetA = 335;         // Z loc A side
  static constexpr float ZdetC = 82;          // Z loc C side
  static constexpr float ChannelWidth = 13.02;       // channel width in ps
  static constexpr float MV_2_Nchannels = 2.2857143; //amplitude channel 7 mV ->16channels
  static constexpr float MV_2_NchannelsInverse = 0.437499997; //inverse amplitude channel 7 mV ->16channels
