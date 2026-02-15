"========================
  Ride
========================"

Object subclass: Ride [
  | rideID pickupLocation dropoffLocation distance |

  initialize [
    rideID := ''.
    pickupLocation := ''.
    dropoffLocation := ''.
    distance := 0.
  ]

  rideID [ ^ rideID ]
  rideID: anObject [ rideID := anObject ]

  pickupLocation [ ^ pickupLocation ]
  pickupLocation: aString [ pickupLocation := aString ]

  dropoffLocation [ ^ dropoffLocation ]
  dropoffLocation: aString [ dropoffLocation := aString ]

  distance [ ^ distance ]
  distance: aNumber [ distance := aNumber ]

  fare [
    ^ self distance * 1.0
  ]

  scaledString: aNumber scale: n [
    | sd str |
    sd := aNumber asScaledDecimal: n.
    str := sd printString.
    "gst prints ScaledDecimal like 4.80s2; remove the suffix"
    ^ str copyUpTo: $s
  ]

  rideDetails [
    | distStr fareStr |
    distStr := self scaledString: self distance scale: 2.
    fareStr := self scaledString: self fare scale: 2.

    ^ String streamContents: [ :s |
      s
        nextPutAll: 'RideID: '; nextPutAll: self rideID asString; cr;
        nextPutAll: 'Pickup: '; nextPutAll: self pickupLocation; cr;
        nextPutAll: 'Dropoff: '; nextPutAll: self dropoffLocation; cr;
        nextPutAll: 'Distance: '; nextPutAll: distStr; nextPutAll: ' miles'; cr;
        nextPutAll: 'Fare: $'; nextPutAll: fareStr
    ].
  ]
]

Ride class extend [
  id: anId pickup: p dropoff: d distance: miles [
    | obj |
    obj := self basicNew.
    obj initialize.
    obj
      rideID: anId;
      pickupLocation: p;
      dropoffLocation: d;
      distance: miles.
    ^ obj
  ]
]


"========================
  StandardRide
========================"

Ride subclass: StandardRide [
  fare [
    ^ self distance * 1.25
  ]
]


"========================
  PremiumRide
========================"

Ride subclass: PremiumRide [
  fare [
    ^ (self distance * 2.50) + 3.00
  ]
]


"========================
  Driver
========================"

Object subclass: Driver [
  | driverID name rating assignedRides |

  initialize [
    driverID := ''.
    name := ''.
    rating := 5.0.
    assignedRides := OrderedCollection new.
  ]

  driverID [ ^ driverID ]
  name [ ^ name ]
  rating [ ^ rating ]

  driverID: anId [ driverID := anId ]
  name: aString [ name := aString ]
  rating: aNumber [ rating := aNumber ]

  ensureAssignedRides [
    assignedRides isNil ifTrue: [ assignedRides := OrderedCollection new ].
  ]

  scaledString: aNumber scale: n [
    | sd str |
    sd := aNumber asScaledDecimal: n.
    str := sd printString.
    ^ str copyUpTo: $s
  ]

  addRide: aRide [
    self ensureAssignedRides.
    assignedRides add: aRide.
  ]

  completedRides [
    self ensureAssignedRides.
    ^ assignedRides copy
  ]

  getDriverInfo [
    | ratingStr |
    self ensureAssignedRides.
    ratingStr := self scaledString: self rating scale: 2.

    ^ String streamContents: [ :s |
      s
        nextPutAll: 'DriverID: '; nextPutAll: self driverID asString; cr;
        nextPutAll: 'Name: '; nextPutAll: self name; cr;
        nextPutAll: 'Rating: '; nextPutAll: ratingStr; cr;
        nextPutAll: 'Completed rides: '; nextPutAll: assignedRides size asString
    ].
  ]
]

Driver class extend [
  id: anId name: aName rating: aRating [
    | obj |
    obj := self basicNew.
    obj initialize.
    obj
      driverID: anId;
      name: aName;
      rating: aRating.
    ^ obj
  ]
]


"========================
  Rider
========================"

Object subclass: Rider [
  | riderID name requestedRides |

  initialize [
    riderID := ''.
    name := ''.
    requestedRides := OrderedCollection new.
  ]

  riderID [ ^ riderID ]
  name [ ^ name ]

  riderID: anId [ riderID := anId ]
  name: aString [ name := aString ]

  ensureRequestedRides [
    requestedRides isNil ifTrue: [ requestedRides := OrderedCollection new ].
  ]

  requestRide: aRide [
    self ensureRequestedRides.
    requestedRides add: aRide.
  ]

  viewRides [
    self ensureRequestedRides.
    ^ requestedRides collect: [ :r | r rideDetails ]
  ]

  getRiderInfo [
    self ensureRequestedRides.
    ^ String streamContents: [ :s |
      s
        nextPutAll: 'RiderID: '; nextPutAll: self riderID asString; cr;
        nextPutAll: 'Name: '; nextPutAll: self name; cr;
        nextPutAll: 'Requested rides: '; nextPutAll: requestedRides size asString
    ].
  ]
]

Rider class extend [
  id: anId name: aName [
    | obj |
    obj := self basicNew.
    obj initialize.
    obj
      riderID: anId;
      name: aName.
    ^ obj
  ]
]


"========================
  Demo
========================"

| r1 r2 rides driver rider |

r1 := StandardRide id: 'R-1001' pickup: 'Campus' dropoff: 'Downtown' distance: 4.2.
r2 := PremiumRide  id: 'R-2001' pickup: 'Airport' dropoff: 'Hotel'    distance: 12.5.

rides := OrderedCollection new.
rides add: r1; add: r2.

Transcript show: '--- Polymorphic ride listing ---'; cr.
rides do: [ :ride |
  Transcript show: ride rideDetails; cr; cr
].

driver := Driver id: 'D-77' name: 'Asha' rating: 4.8.
driver addRide: r1.
driver addRide: r2.

rider := Rider id: 'U-55' name: 'Nirajan'.
rider requestRide: r1.
rider requestRide: r2.

Transcript show: '--- Driver info ---'; cr.
Transcript show: driver getDriverInfo; cr; cr.

Transcript show: '--- Rider history ---'; cr.
rider viewRides do: [ :details |
  Transcript show: details; cr; cr
].
