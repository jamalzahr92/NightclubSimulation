================================================================================
NIGHT CLUB SIMULATION
A Real-Time Audio-Reactive Virtual Environment in Unreal Engine 5.6
================================================================================

Developed as part of the Visual Computing Seminar (Course 6178, SoSe 2026)
University of Passau
Supervised by: 
  - Dr. Christoph Heinzl 
  - Alexander Gall 

Group 3

Authors:
  - Jamal Zahr
  - Sahar Barekati

================================================================================
PROJECT OVERVIEW
================================================================================

Night Club Simulation is a real-time audio-reactive nightclub environment built
entirely in Unreal Engine 5.6 using Blueprints. The system captures live audio
via microphone, performs real-time FFT spectral analysis, and drives a full suite
of synchronized visual effects including moving spotlights, laser beams, particle
systems, pyrotechnic fire effects, camera shake, and a dancing character — all
reacting autonomously to any music played through the microphone input.

No pre-authored timelines or manual triggering are used. All visual behavior
emerges directly from the live audio signal.

================================================================================
REQUIREMENTS
================================================================================

ENGINE
------
- Unreal Engine 5.6 (exactly — other versions not tested and may not work)
- Visual Studio 2022
REQUIRED PLUGINS (enable all before running)
--------------------------------------------
Go to Edit → Plugins and ensure the following are enabled:

Audio & Media:
  - WMF Media
  - Media Framework Utilities
  - Audio Capture

Rendering & Effects:
  - Niagara
  - Niagara Extras

General:
  - Enhanced Input (if using shoot-to-advance screen feature)

After enabling any plugins, restart the editor.

RECOMMENDED HARDWARE SPECS
---------------------------
- CPU: Intel Core i7 / AMD Ryzen 7 or better (multi-core for shader compilation)
- GPU: NVIDIA RTX 2070 or better (RTX recommended for VSM shadow support)
- RAM: 16 GB minimum, 32 GB recommended
- Storage: SSD required (HDD will cause severe shader compilation delays)
- Microphone: Any working Windows microphone input (built-in laptop mic works)
- OS: Windows 10 / Windows 11 (64-bit)

Note: First launch will compile shaders and may take 10-30 minutes depending
on hardware. Subsequent launches use cached shaders and are significantly faster.

================================================================================
BEFORE YOU OPEN THE PROJECT
================================================================================

1. MICROPHONE SETUP
   - Make sure your microphone is set as the Default Input Device in Windows
   - Go to: Settings → System → Sound → Input
   - Select your microphone and confirm the input level bar moves when you speak
   - If using Windows 11 and settings appear locked, use the classic Control Panel:
     Control Panel → Hardware and Sound → Sound → Recording tab
   - Microphone volume should be set to 100
   - Make sure the microphone is not muted (no X icon on the speaker symbol)

2. WINDOWS MICROPHONE PERMISSION
   - Go to: Settings → Privacy & Security → Microphone
   - Enable "Microphone access" (top toggle)
   - Enable "Let apps access your microphone"
   - Enable "Let desktop apps access your microphone"
   - Unreal Engine should appear in the desktop apps list after first run

3. SHADER CACHE
   - For faster load times, the DDC (Derived Data Cache) should be on an SSD
   - Optionally add to Config/DefaultEngine.ini:
     [InstalledDerivedDataBackendGraph]
     Local=(Type=FileSystem, ReadOnly=false, Clean=false, Flush=false,
     Path=C:\DDC)
   - Change C:\DDC to any fast drive location you prefer

================================================================================
HOW TO RUN THE PROJECT
================================================================================

1. Open the project in Unreal Engine 5.6
2. Navigate to the main demo map:
   Content → Maps → Demonstration_Small_Stage_Test
3. Double-click to open it
4. Press the green PLAY button (or Alt+P)
5. The system starts capturing audio immediately on Play
6. Play music through speakers near your microphone or through your PC audio
7. All visual systems activate and react to the audio automatically

FIRST TIME RUNNING:
- If visual systems seem unresponsive, wait 2-3 seconds after pressing Play
  for the audio capture to initialize fully
- If values still show 0, stop Play, check microphone settings, and try again

================================================================================
SYSTEMS OVERVIEW
================================================================================

AUDIO ANALYSIS (BP_AudioAnalyzer)
----------------------------------
The core of the project. Captures microphone input via Audio Capture Component,
routes it through SM_AudioCapture submix, and performs FFT analysis every frame.

Frequency bands analyzed:
  - Bass:   20, 40, 50, 60, 70, 80,100 Hz
  - Mid:    250, 500, 800, 1500 Hz
  - Vocal:  2000, 3000, 4000, 5000 Hz
  - High:   5000, 8000, 10000, 120000 Hz

Beat detection uses a 5-condition AND gate on the bass band, with a 0.3 second
cooldown between hits. All values are broadcast via Event Dispatchers:
  - onBassHit (fires on detected bass beat)
  - onBassValueUpdated (continuous normalized bass 0-1)
  - onHighUpdated (continuous high energy 0-1)
  - onVocalUpdated (continuous vocal energy 0-1)
  - onMidHit (fires on detected mid/snare hit)

LIGHTING (BP_BassSpotLight)
-----------------------------
Moving head spotlights with pan (yaw) and tilt (pitch) axes driven by bass hits.
- Arms mesh rotates on yaw (left/right)
- Head mesh rotates on pitch (up/down) independently
- Intensity spikes on bass hit and decays toward zero each frame
- Color selected by GetMoodColor function based on HitRate, SmoothedBass,
  HighEnergy, and Volume proxies (4 mood palettes: energetic, heavy, bright, calm)
- All spotlights share a coordinated color and yaw value per hit

AMBIENT LIGHT (BP_AmbientLight)
---------------------------------
Volume-driven intensity with smooth A-to-B rotation loop.
- Intensity mapped directly from SmoothedVolume
- Sweeps between two designer-set rotation points via Timeline
- Sweep speed optionally driven by volume (faster when louder)

PARTICLE EFFECTS
-----------------
NS_BassDisperse:
  Speaker burst particles firing on each bass hit.
  Spawn count scales with bass intensity.

NS_ConcertFire:
  Pyrotechnic fire columns at stage edges. Two emitters (fire + smoke).
  Activates in short bursts on bass hits, deactivates after 0.4 seconds.
  Fire material uses Perlin noise with panning UV for organic movement.

Vortex System:
  Continuously spawning vortex particles. On bass hit, a Point Attraction
  Force module (set to repulsion/negative strength) is spiked via User Parameter,
  causing all currently alive particles to expand radially outward, then
  contract back as the value decays via FInterpTo each tick.

LASER BEAMS (BP_LaserManager / BP_LaserBeam)
----------------------------------------------
Niagara ribbon-based laser beams with world-space endpoints exposed as User
Parameters. BP_LaserManager spawns and controls multiple beams, repositioning
them randomly on each bass hit. Approximately 50% of beams reposition per hit
for a natural, non-uniform look. Beams drift slowly between hits.

CAMERA SHAKE (BS_BassShake)
-----------------------------
LegacyCameraShake fires on each bass hit. Intensity scales with normalized bass
value via MapRangeClamped (0.5 at minimum hit, 2.0 at maximum hit).
Duration: 0.3 seconds. Short and sharp for physical impact.

CHARACTER ANIMATION (BP_PawnDancer)
-------------------------------------
UE5 default Mannequin with Animation Blueprint (ABP_Pawn) driving a 1D Blend
Space (BS_DanceBlend) between idle (0.0) and dance (1.0) animations.
DanceWeight is updated via FInterpTo targeting a value derived from
SmoothedVolume through MapRangeClamped. InterpSpeed of 2.0 gives natural
transitions. bInitialized guard prevents GetActorOfClass from running every frame.

PRESENTATION SCREEN (BP_SlideScreen)
--------------------------------------
A screen mesh displays slide textures. Shooting the screen (line trace or
projectile hit) advances to the next slide. Uses Dynamic Material Instance
with a Texture 2D parameter swapped at runtime. Slides wrap back to the
first after the last slide.

CROWD SYSTEM (BP_CrowdMember)
-------------------------------
Single Blueprint that randomly selects a dance animation on BeginPlay from a
populated array. Each instance uses a random start delay (0-2 seconds) so
crowd members do not move in perfect sync. Approximately 30% chance to change
dance animation on each bass hit. Crowd members use varied material colors
and slight scale variation to avoid a cloned appearance.

ENVIRONMENT
------------
- Exponential Height Fog for volumetric haze and laser/spotlight visibility
- Directional Light as low-intensity desaturated scene fill
- Sky Atmosphere for ambient diffusion
- Static mesh stage with speaker housings, light rig, and screen

================================================================================
KNOWN ISSUES AND LIMITATIONS
================================================================================

1. MOOD DETECTION IS PROXY-BASED
   True musical mood (happy, sad, tense) cannot be determined from FFT magnitude
   values alone. The mood color system uses measurable energy proxies (HitRate,
   SmoothedBass, HighEnergy, Volume) that correlate with mood rather than
   detecting it directly. This is a fundamental limitation of real-time FFT
   analysis, not specific to this implementation.

2. SHADER COMPILATION ON FIRST LAUNCH
   First launch will trigger full shader compilation which can take 10-30 minutes.
   This is normal UE5 behavior. Do not close the editor during this process.

3. MICROPHONE SENSITIVITY
   All detection thresholds are calibrated for a typical laptop microphone at
   approximately 0.5-1.0 meter distance from speakers. Very quiet rooms or very
   loud rooms may require threshold recalibration in BP_AudioAnalyzer.

4. VSM SHADOW OVERFLOW WARNING
   The message "[VSM] One Pass Projection max lights overflow" may appear in the
   viewport. This is a warning not an error. To suppress it, open the console
   (backtick key) and enter:
   r.Shadow.Virtual.OnePassProjection.MaxLightsPerPixel 8
   To make permanent, add to Config/DefaultEngine.ini under
   [/Script/Engine.RendererSettings]:
   r.Shadow.Virtual.OnePassProjection.MaxLightsPerPixel=8

5. DIRECTIONAL LIGHT WARNING
   Only one Directional Light should exist in the level. If the warning
   "Multiple directional lights competing" appears, delete any extra
   Directional Light actors from the World Outliner.

6. LIVE PHONE STREAMING
   UE5's Electra Media Player does not support live HTTP video capture streams.
   Live phone camera feed requires routing through VLC or OBS Virtual Camera
   as an intermediary to convert the stream to a Windows capture device.
   This feature may not be available in the demo build.

7. ANIMATION SNAPPINESS
   If character animation transitions feel abrupt, the FInterpTo speed in
   ABP_Pawn Event Graph can be lowered (currently 2.0). Also verify the
   Blend Space Interpolation Time is not set to 0.

================================================================================
CALIBRATION GUIDE
================================================================================

If the system is not responding correctly to music, these are the values to
adjust in BP_AudioAnalyzer:

Bass Hit Detection Thresholds:
  - Delta > 0.04          (frame-to-frame bass change — raise if too sensitive)
  - SmoothedBass > 10    (minimum bass energy — raise if triggering on silence)
  - MidEnergy < 0.1       (mid suppressor — lower if missing hits during full mix)
  - Ratio > 2.0           (bass dominance — raise if triggering on non-bass sounds)
  - BassDropCooldown 0.3  (minimum time between hits — raise for slower music)

To check current values during Play, temporarily add Print String nodes after
each Get Magnitude call. Values typically range:
  - SmoothedBass: 0.0 to 3.0+ on strong bass hits
  - MidEnergy: 0.0 to 0.5 in a full mix
  - HighEnergy: 0.0 to 0.1
  - Volume (SmoothedVolume): 0.0 to 30.0+

================================================================================
PROJECT STRUCTURE
================================================================================

Content/
  Blueprints/
    Actors/
      BP_AudioAnalyzer       — core audio analysis and dispatcher
      BP_BassSpotLight       — pan/tilt moving head spotlight
      BP_AmbientLight        — volume-driven ambient light with sweep
      BP_LaserManager        — spawns and controls laser beams
      BP_LaserBeam           — individual Niagara ribbon laser
      BP_ConcertFire         — pyrotechnic fire particle actor
      BP_SpeakerParticles    — bass disperse burst particles
      BP_SlideScreen         — shoot-to-advance presentation screen
      BP_CrowdMember         — single crowd dancer with random animation
      BP_PawnDancer          — main dancing character pawn
    Parent/
      BP_LightsParent        — base class handling dispatcher binding
      BP_SpotlightsParent    — base class for spotlight hierarchy

  FX/
    NS_BassDisperse          — speaker burst Niagara system
    NS_ConcertFire           — pyrotechnic fire/smoke Niagara system
    NS_LaserBeam             — ribbon beam Niagara system
    NS_Vortex                — vortex Niagara system

  Materials/
    M_Laser                  — unlit translucent laser beam material
    M_ConcertFire            — animated fire material with Perlin noise
    M_SlideScreen            — unlit screen material with texture parameter

  MetaSounds/
    SM_BassCapture           — Sound Submix for audio analysis routing

  Maps/
    Demonstration_Small_Stage_Test   — main demo map (open this to run)

  Animation/
    BS_DanceBlend            — 1D Blend Space idle to dance
    ABP_Pawn                 — Animation Blueprint for dancer

================================================================================
CREDITS
================================================================================

Engine: Unreal Engine 5.6 by Epic Games
Dance Animations: Mixamo by Adobe (free tier)
Stage Assets: Modular Concert Stage by Modulus Group
University: University of Passau, Visual Computing Seminar, SoSe 2026
Supervisors: Dr. Christoph Heinzl & Alexander Gall

================================================================================
