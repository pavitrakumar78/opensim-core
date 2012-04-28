#ifndef __ActuatorPowerProbe_h__
#define __ActuatorPowerProbe_h__

// ActuatorPowerProbe.h
// Author: Ajay Seth, Tim Dorn
/*
 * Copyright (c)  2011, Stanford University. All rights reserved. 
* Use of the OpenSim software in source form is permitted provided that the following
* conditions are met:
* 	1. The software is used only for non-commercial research and education. It may not
*     be used in relation to any commercial activity.
* 	2. The software is not distributed or redistributed.  Software distribution is allowed 
*     only through https://simtk.org/home/opensim.
* 	3. Use of the OpenSim software or derivatives must be acknowledged in all publications,
*      presentations, or documents describing work in which OpenSim or derivatives are used.
* 	4. Credits to developers may not be removed from executables
*     created from modifications of the source.
* 	5. Modifications of source code must retain the above copyright notice, this list of
*     conditions and the following disclaimer. 
* 
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
*  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
*  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
*  SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
*  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
*  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR BUSINESS INTERRUPTION) OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
*  WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


// INCLUDE
#include "Actuator.h"
#include "Probe.h"
#include "Model.h"


namespace OpenSim {

class Model;

//==============================================================================
//==============================================================================
/**
 * ActuatorPowerProbe is a ModelComponent Probe for computing an operation on a 
 * actuator power or sum of actuator powers in the model during a simulation.
 * E.g. Work is the integral of power with respect to time.
 *
 * @author Ajay Seth, Tim Dorn
 * @version 1.0
 */
class OSIMSIMULATION_API ActuatorPowerProbe : public Probe  
{
	OpenSim_DECLARE_CONCRETE_OBJECT(ActuatorPowerProbe, Probe);
//=============================================================================
// DATA
//=============================================================================
protected:

//=============================================================================
// METHODS
//=============================================================================
public:
	//--------------------------------------------------------------------------
	// Constructor(s) and Setup
	//--------------------------------------------------------------------------
	/** Default constructor */
	ActuatorPowerProbe();
	/** Convenience constructor */
	ActuatorPowerProbe(Array<std::string> actuator_names);
	/** Copy constructor */
	ActuatorPowerProbe(const ActuatorPowerProbe &aActuatorPowerProbe);
	/** Destructor */
	virtual ~ActuatorPowerProbe();
	void copyData(const ActuatorPowerProbe &aProbe);

private:
	void setNull();
	void setupProperties();

public:

	//--------------------------------------------------------------------------
	// Operators
	//--------------------------------------------------------------------------
#ifndef SWIG
	ActuatorPowerProbe& operator=(const ActuatorPowerProbe &aActuatorPowerProbe);
#endif


	//--------------------------------------------------------------------------
	// Get and Set
	//--------------------------------------------------------------------------
	/** Returns the names of the Actuators being probed. */
	const Property<std::string>& getActuatorNames() const;

	/** Sets the names of the Actuators being probed. */
	void setActuatorNames(const Array<std::string>& aActuatorNames);



	//-----------------------------------------------------------------------------
	// Computation
	//-----------------------------------------------------------------------------
	/** Compute the Actuator power upon which the Probe operation will be based on. */
	virtual SimTK::Vector computeProbeValue(const SimTK::State& state) const;


	//--------------------------------------------------------------------------
	// ModelComponent Interface
	//--------------------------------------------------------------------------
protected:
	virtual void setup(Model& aModel);
	

//=============================================================================
};	// END of class ActuatorPowerProbe
//=============================================================================
//=============================================================================

} // end of namespace OpenSim

#endif // __ActuatorPowerProbe_h__


