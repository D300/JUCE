#pragma once

#include <vector>

namespace juce
{
namespace lv2
{

struct BundleResource
{
    const char* name;
    const char* contents;
};

struct Bundle
{
    const char* name;
    std::vector<BundleResource> contents;

    static std::vector<Bundle> getAllBundles();
};

}
}

std::vector<juce::lv2::Bundle> juce::lv2::Bundle::getAllBundles()
{
    return {
juce::lv2::Bundle
{
"instance-access",
{
juce::lv2::BundleResource
{
"instance-access.ttl",
R"lv2ttl(@prefix ia: <http://lv2plug.in/ns/ext/instance-access#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/instance-access>
    a lv2:Feature ;
    rdfs:label "instance access" ;
    rdfs:comment "A feature that provides access to a plugin instance." ;
    rdfs:seeAlso <instance-access.h> ,
        <instance-access.meta.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/instance-access>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 6 ;
    rdfs:seeAlso <instance-access.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"instance-access.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix ia: <http://lv2plug.in/ns/ext/instance-access#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/instance-access>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 Instance Access" ;
    doap:shortdesc "Provides access to the LV2_Handle of a plugin." ;
    doap:created "2010-10-04" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-instance-access-1.4.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2011-05-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-instance-access-1.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system for installation."
            ] , [
                rdfs:label "Switch to ISC license."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2010-10-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-instance-access-1.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a feature which allows plugin UIs to get a direct handle
to an LV2 plugin instance (LV2_Handle), if possible.

Note that the use of this extension by UIs violates the important principle of
UI/plugin separation, and is potentially a source of many problems.
Accordingly, **use of this extension is highly discouraged**, and plugins
should not expect hosts to support it, since it is often impossible to do so.

To support this feature the host must pass an LV2_Feature struct to the UI
instantiate method with URI LV2_INSTANCE_ACCESS_URI and data pointed directly
to the LV2_Handle of the plugin instance.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"port-groups",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/port-groups>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 4 ;
    rdfs:seeAlso <port-groups.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"port-groups.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix pg: <http://lv2plug.in/ns/ext/port-groups#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/port-groups>
    a owl:Ontology ;
    rdfs:label "LV2 Port Groups" ;
    rdfs:comment "Multi-channel groups of LV2 ports." ;
    rdfs:seeAlso <port-groups.meta.ttl> .

pg:Group
    a rdfs:Class ;
    rdfs:label "Port Group" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty lv2:symbol ;
        owl:cardinality 1 ;
        rdfs:comment "A Group MUST have exactly one string lv2:symbol."
    ] ;
    rdfs:comment "A set of ports that are logicaly grouped together." .

pg:InputGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:Group ;
    rdfs:label "Input Group" ;
    rdfs:comment "A group which contains exclusively inputs." .

pg:OutputGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:Group ;
    rdfs:label "Output Group" ;
    rdfs:comment "A group which contains exclusively outputs." .

pg:Element
    a rdfs:Class ;
    rdfs:label "Element" ;
    rdfs:comment "An ordered element of a group." ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty lv2:designation ;
        owl:cardinality 1 ;
        rdfs:comment "An element MUST have exactly one lv2:designation."
    ] ;
    rdfs:comment "An element of a group, with a designation and optional index." .

pg:element
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range pg:Element ;
    rdfs:label "element" ;
    rdfs:comment "An element within a port group." .

pg:sideChainOf
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "side-chain of" ;
    rdfs:comment "Port or group is a side chain of another." .

pg:subGroupOf
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain pg:Group ;
    rdfs:range pg:Group ;
    rdfs:label "sub-group of" ;
    rdfs:comment "Group is a child of another group." .

pg:source
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain pg:OutputGroup ;
    rdfs:range pg:InputGroup ;
    rdfs:label "source" ;
    rdfs:comment "Port or group that this group is the output of." .

pg:mainInput
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain lv2:Plugin ;
    rdfs:range pg:InputGroup ;
    rdfs:label "main input" ;
    rdfs:comment "Input group that is the primary input of the plugin." .

pg:mainOutput
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain lv2:Plugin ;
    rdfs:range pg:OutputGroup ;
    rdfs:label "main output" ;
    rdfs:comment "Output group that is the primary output of the plugin." .

pg:group
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain lv2:Port ;
    rdfs:range pg:Group ;
    rdfs:label "group" ;
    rdfs:comment "Group that this port is a part of." .

pg:DiscreteGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:Group ;
    rdfs:label "Discrete Group" ;
    rdfs:comment "A group of discrete channels." .

pg:left
    a lv2:Channel ;
    rdfs:label "left" ;
    rdfs:comment "The left channel of a stereo audio group." .

pg:right
    a lv2:Channel ;
    rdfs:label "right" ;
    rdfs:comment "The right channel of a stereo audio group." .

pg:center
    a lv2:Channel ;
    rdfs:label "center" ;
    rdfs:comment "The center channel of a discrete audio group." .

pg:side
    a lv2:Channel ;
    rdfs:label "side" ;
    rdfs:comment "The side channel of a mid-side audio group." .

pg:centerLeft
    a lv2:Channel ;
    rdfs:label "center left" ;
    rdfs:comment "The center-left channel of a 7.1 wide surround sound group." .

pg:centerRight
    a lv2:Channel ;
    rdfs:label "center right" ;
    rdfs:comment "The center-right channel of a 7.1 wide surround sound group." .

pg:sideLeft
    a lv2:Channel ;
    rdfs:label "side left" ;
    rdfs:comment "The side-left channel of a 6.1 or 7.1 surround sound group." .

pg:sideRight
    a lv2:Channel ;
    rdfs:label "side right" ;
    rdfs:comment "The side-right channel of a 6.1 or 7.1 surround sound group." .

pg:rearLeft
    a lv2:Channel ;
    rdfs:label "rear left" ;
    rdfs:comment "The rear-left channel of a surround sound group." .

pg:rearRight
    a lv2:Channel ;
    rdfs:label "rear right" ;
    rdfs:comment "The rear-right channel of a surround sound group." .

pg:rearCenter
    a lv2:Channel ;
    rdfs:label "rear center" ;
    rdfs:comment "The rear-center channel of a surround sound group." .

pg:lowFrequencyEffects
    a lv2:Channel ;
    rdfs:label "low-frequency effects" ;
    rdfs:comment "The LFE channel of a *.1 surround sound group." .

pg:MonoGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "Mono" ;
    rdfs:comment "A single channel audio group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:center
    ] .

pg:StereoGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "Stereo" ;
    rdfs:comment "A 2-channel discrete stereo audio group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:right
    ] .

pg:MidSideGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "Mid-Side Stereo" ;
    rdfs:comment "A 2-channel mid-side stereo audio group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:center
    ] , [
        lv2:index 1 ;
        lv2:designation pg:side
    ] .

pg:ThreePointZeroGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "3.0 Surround" ;
    rdfs:comment "A 3.0 discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:right
    ] , [
        lv2:index 2 ;
        lv2:designation pg:rearCenter
    ] .

pg:FourPointZeroGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "4.0 Surround" ;
    rdfs:comment "A 4.0 (Quadraphonic) discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:center
    ] , [
        lv2:index 2 ;
        lv2:designation pg:right
    ] , [
        lv2:index 3 ;
        lv2:designation pg:rearCenter
    ] .

pg:FivePointZeroGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "5.0 Surround" ;
    rdfs:comment "A 5.0 (3-2 stereo) discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:center
    ] , [
        lv2:index 2 ;
        lv2:designation pg:right
    ] , [
        lv2:index 3 ;
        lv2:designation pg:rearLeft
    ] , [
        lv2:index 4 ;
        lv2:designation pg:rearRight
    ] .

pg:FivePointOneGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "5.1 Surround" ;
    rdfs:comment "A 5.1 (3-2 stereo with sub) discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:center
    ] , [
        lv2:index 2 ;
        lv2:designation pg:right
    ] , [
        lv2:index 3 ;
        lv2:designation pg:rearLeft
    ] , [
        lv2:index 4 ;
        lv2:designation pg:rearRight
    ] , [
        lv2:index 5 ;
        lv2:designation pg:lowFrequencyEffects
    ] .

pg:SixPointOneGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "6.1 Surround" ;
    rdfs:comment "A 6.1 discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:center
    ] , [
        lv2:index 2 ;
        lv2:designation pg:right
    ] , [
        lv2:index 3 ;
        lv2:designation pg:sideLeft
    ] , [
        lv2:index 4 ;
        lv2:designation pg:sideRight
    ] , [
        lv2:index 5 ;
        lv2:designation pg:rearCenter
    ] , [
        lv2:index 6 ;
        lv2:designation pg:lowFrequencyEffects
    ] .

pg:SevenPointOneGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "7.1 Surround" ;
    rdfs:comment "A 7.1 discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:center
    ] , [
        lv2:index 2 ;
        lv2:designation pg:right
    ] , [
        lv2:index 3 ;
        lv2:designation pg:sideLeft
    ] , [
        lv2:index 4 ;
        lv2:designation pg:sideRight
    ] , [
        lv2:index 5 ;
        lv2:designation pg:rearLeft
    ] , [
        lv2:index 6 ;
        lv2:designation pg:rearRight
    ] , [
        lv2:index 7 ;
        lv2:designation pg:lowFreq)lv2ttl" R"lv2ttl(uencyEffects
    ] .

pg:SevenPointOneWideGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:DiscreteGroup ;
    rdfs:label "7.1 Surround (Wide)" ;
    rdfs:comment "A 7.1 wide discrete surround sound group." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:left
    ] , [
        lv2:index 1 ;
        lv2:designation pg:centerLeft
    ] , [
        lv2:index 2 ;
        lv2:designation pg:center
    ] , [
        lv2:index 3 ;
        lv2:designation pg:centerRight
    ] , [
        lv2:index 4 ;
        lv2:designation pg:right
    ] , [
        lv2:index 5 ;
        lv2:designation pg:rearLeft
    ] , [
        lv2:index 6 ;
        lv2:designation pg:rearRight
    ] , [
        lv2:index 7 ;
        lv2:designation pg:lowFrequencyEffects
    ] .

pg:letterCode
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain lv2:Channel ;
    rdfs:range rdf:PlainLiteral ;
    rdfs:label "ambisonic letter code" ;
    rdfs:comment "The YuMa letter code for an Ambisonic channel." .

pg:harmonicDegree
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain lv2:Channel ;
    rdfs:range xsd:integer ;
    rdfs:label "harmonic degree" ;
    rdfs:comment "The degree coefficient (l) of the spherical harmonic for an Ambisonic channel." .

pg:harmonicIndex
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain lv2:Channel ;
    rdfs:range xsd:integer ;
    rdfs:label "harmonic index" ;
    rdfs:comment "The index coefficient (m) of the spherical harmonic for an Ambisonic channel." .

pg:ACN0
    a lv2:Channel ;
    pg:letterCode "W" ;
    pg:harmonicDegree 0 ;
    pg:harmonicIndex 0 ;
    rdfs:label "ACN0" ;
    rdfs:comment "Ambisonic channel 0 (W): degree 0, index 0." .

pg:ACN1
    a lv2:Channel ;
    pg:letterCode "Y" ;
    pg:harmonicDegree 1 ;
    pg:harmonicIndex -1 ;
    rdfs:label "ACN1" ;
    rdfs:comment "Ambisonic channel 1 (Y): degree 1, index -1." .

pg:ACN2
    a lv2:Channel ;
    pg:letterCode "Z" ;
    pg:harmonicDegree 1 ;
    pg:harmonicIndex 0 ;
    rdfs:label "ACN2" ;
    rdfs:comment "Ambisonic channel 2 (Z): degree 1, index 0." .

pg:ACN3
    a lv2:Channel ;
    pg:letterCode "X" ;
    pg:harmonicDegree 1 ;
    pg:harmonicIndex 1 ;
    rdfs:label "ACN3" ;
    rdfs:comment "Ambisonic channel 3 (X): degree 1, index 1." .

pg:ACN4
    a lv2:Channel ;
    pg:letterCode "V" ;
    pg:harmonicDegree 2 ;
    pg:harmonicIndex -2 ;
    rdfs:label "ACN4" ;
    rdfs:comment "Ambisonic channel 4 (V): degree 2, index -2." .

pg:ACN5
    a lv2:Channel ;
    pg:letterCode "T" ;
    pg:harmonicDegree 2 ;
    pg:harmonicIndex -1 ;
    rdfs:label "ACN5" ;
    rdfs:comment "Ambisonic channel 5 (T): degree 2, index -1." .

pg:ACN6
    a lv2:Channel ;
    pg:letterCode "R" ;
    pg:harmonicDegree 2 ;
    pg:harmonicIndex 0 ;
    rdfs:label "ACN6" ;
    rdfs:comment "Ambisonic channel 6 (R): degree 2, index 0." .

pg:ACN7
    a lv2:Channel ;
    pg:letterCode "S" ;
    pg:harmonicDegree 2 ;
    pg:harmonicIndex 1 ;
    rdfs:label "ACN7" ;
    rdfs:comment "Ambisonic channel 7 (S): degree 2, index 1." .

pg:ACN8
    a lv2:Channel ;
    pg:letterCode "U" ;
    pg:harmonicDegree 2 ;
    pg:harmonicIndex 2 ;
    rdfs:label "ACN8" ;
    rdfs:comment "Ambisonic channel 8 (U): degree 2, index 2." .

pg:ACN9
    a lv2:Channel ;
    pg:letterCode "Q" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex -3 ;
    rdfs:label "ACN9" ;
    rdfs:comment "Ambisonic channel 9 (Q): degree 3, index -3." .

pg:ACN10
    a lv2:Channel ;
    pg:letterCode "O" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex -2 ;
    rdfs:label "ACN10" ;
    rdfs:comment "Ambisonic channel 10 (O): degree 3, index -2." .

pg:ACN11
    a lv2:Channel ;
    pg:letterCode "M" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex -1 ;
    rdfs:label "ACN11" ;
    rdfs:comment "Ambisonic channel 11 (M): degree 3, index -1." .

pg:ACN12
    a lv2:Channel ;
    pg:letterCode "K" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex 0 ;
    rdfs:label "ACN12" ;
    rdfs:comment "Ambisonic channel 12 (K): degree 3, index 0." .

pg:ACN13
    a lv2:Channel ;
    pg:letterCode "L" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex 1 ;
    rdfs:label "ACN13" ;
    rdfs:comment "Ambisonic channel 13 (L): degree 3, index 1." .

pg:ACN14
    a lv2:Channel ;
    pg:letterCode "N" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex 2 ;
    rdfs:label "ACN14" ;
    rdfs:comment "Ambisonic channel 14 (N): degree 3, index 2." .

pg:ACN15
    a lv2:Channel ;
    pg:letterCode "P" ;
    pg:harmonicDegree 3 ;
    pg:harmonicIndex 3 ;
    rdfs:label "ACN15" ;
    rdfs:comment "Ambisonic channel 15 (P): degree 3, index 3." .

pg:AmbisonicGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:Group ;
    rdfs:label "Ambisonic Group" ;
    rdfs:comment "A group of Ambisonic channels." .

pg:AmbisonicBH1P0Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH1P0" ;
    rdfs:comment "Ambisonic B stream of horizontal order 1 and peripheral order 0." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN3
    ] .

pg:AmbisonicBH1P1Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH1P1" ;
    rdfs:comment "Ambisonic B stream of horizontal order 1 and peripheral order 1." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN2
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN3
    ] .

pg:AmbisonicBH2P0Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH2P0" ;
    rdfs:comment "Ambisonic B stream of horizontal order 2 and peripheral order 0." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN8
    ] .

pg:AmbisonicBH2P1Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH2P1" ;
    rdfs:comment "Ambisonic B stream of horizontal order 2 and peripheral order 1." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN2
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 5 ;
        lv2:designation pg:ACN8
    ] .

pg:AmbisonicBH2P2Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH2P2" ;
    rdfs:comment "Ambisonic B stream of horizontal order 2 and peripheral order 2." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN2
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 5 ;
        lv2:designation pg:ACN5
    ] , [
        lv2:index 6 ;
        lv2:designation pg:ACN6
    ] , [
        lv2:index 7 ;
        lv2:designation pg:ACN7
    ] , [
        lv2:index 8 ;
        lv2:designation pg:ACN8
    ] .

pg:AmbisonicBH3P0Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH3P0" ;
    rdfs:comment "Ambisonic B stream of horizontal order 3 and peripheral order 0." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN8
    ] , [
        lv2:index 5 ;
        lv2:designation pg:ACN9
    ] , [
        lv2:index 6 ;
        lv2:designation pg:ACN15
    ] .

pg:AmbisonicBH3P1Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH3P1" ;
    rdfs:comment "Ambisonic B stream of horizontal order 3 and peripheral order 1." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN2
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 5 ;
        lv2:designation pg:ACN8
    ] , [
        lv2:index 6 ;
        lv2:designation pg:ACN9
    ] , [
        lv2:index 7 ;
        lv2:designation pg:ACN15
    ] .

pg:AmbisonicBH3P2Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH3P2" ;
    rdfs:comment "Ambisonic B stream of horizontal order 3 and peripheral order 2." ;
    pg:e)lv2ttl" R"lv2ttl(lement [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN2
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 5 ;
        lv2:designation pg:ACN5
    ] , [
        lv2:index 6 ;
        lv2:designation pg:ACN6
    ] , [
        lv2:index 7 ;
        lv2:designation pg:ACN7
    ] , [
        lv2:index 8 ;
        lv2:designation pg:ACN8
    ] , [
        lv2:index 9 ;
        lv2:designation pg:ACN9
    ] , [
        lv2:index 10 ;
        lv2:designation pg:ACN15
    ] .

pg:AmbisonicBH3P3Group
    a rdfs:Class ;
    rdfs:subClassOf pg:AmbisonicGroup ;
    rdfs:label "Ambisonic BH3P3" ;
    rdfs:comment "Ambisonic B stream of horizontal order 3 and peripheral order 3." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation pg:ACN0
    ] , [
        lv2:index 1 ;
        lv2:designation pg:ACN1
    ] , [
        lv2:index 2 ;
        lv2:designation pg:ACN2
    ] , [
        lv2:index 3 ;
        lv2:designation pg:ACN3
    ] , [
        lv2:index 4 ;
        lv2:designation pg:ACN4
    ] , [
        lv2:index 5 ;
        lv2:designation pg:ACN5
    ] , [
        lv2:index 6 ;
        lv2:designation pg:ACN6
    ] , [
        lv2:index 7 ;
        lv2:designation pg:ACN7
    ] , [
        lv2:index 8 ;
        lv2:designation pg:ACN8
    ] , [
        lv2:index 9 ;
        lv2:designation pg:ACN9
    ] , [
        lv2:index 10 ;
        lv2:designation pg:ACN10
    ] , [
        lv2:index 11 ;
        lv2:designation pg:ACN11
    ] , [
        lv2:index 12 ;
        lv2:designation pg:ACN12
    ] , [
        lv2:index 13 ;
        lv2:designation pg:ACN13
    ] , [
        lv2:index 14 ;
        lv2:designation pg:ACN14
    ] , [
        lv2:index 15 ;
        lv2:designation pg:ACN15
    ] .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"port-groups.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix pg: <http://lv2plug.in/ns/ext/port-groups#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/port-groups>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 Port Groups" ;
    doap:shortdesc "Multi-channel groups of LV2 ports." ;
    doap:created "2008-00-00" ;
    doap:developer <http://lv2plug.in/ns/meta#larsl> ,
        <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.4" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Replace broken links with detailed Ambisonic channel descriptions."
            ] , [
                rdfs:label "Remove incorrect type of pg:letterCode."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] .

pg:Group
    lv2:documentation """

A group logically combines ports which should be considered part of the same
stream.  For example, two audio ports in a group may form a stereo stream.

Like ports, groups have a lv2:symbol that is unique within the context of the
plugin, where group symbols and port symbols reside in the same namespace.  In
other words, a group on a plugin MUST NOT have the same symbol as any other
group or port on that plugin.  This makes it possible to uniquely reference a
port or group on a plugin with a single identifier and no context.

Group definitions may be shared across plugins for brevity.  For example, a
plugin collection may define a single URI for a pg:StereoGroup with the symbol
"input" and use it in many plugins.

"""^^lv2:Markdown .

pg:sideChainOf
    lv2:documentation """

Indicates that this port or group should be considered a "side chain" of some
other port or group.  The precise definition of "side chain" depends on the
plugin, but in general this group should be considered a modifier to some other
group, rather than an independent input itself.

"""^^lv2:Markdown .

pg:subGroupOf
    lv2:documentation """

Indicates that this group is a child of another group.  This property has no
meaning with respect to plugin execution, but the host may find this
information useful to provide a better user interface.  Note that being a
sub-group does not relax the restriction that the group MUST have a unique
symbol with respect to the plugin.

"""^^lv2:Markdown .

pg:source
    lv2:documentation """

Indicates that this port or group should be considered the "result" of some
other port or group.  This property only makes sense on groups with outputs
when the source is a group with inputs.  This can be used to convey a
relationship between corresponding input and output groups with different
types, for example in a mono to stereo plugin.

"""^^lv2:Markdown .

pg:mainInput
    lv2:documentation """

Indicates that this group should be considered the "main" input, i.e. the
primary task is processing the signal in this group.  A plugin MUST NOT have
more than one pg:mainInput property.

"""^^lv2:Markdown .

pg:mainOutput
    lv2:documentation """

Indicates that this group should be considered the "main" output.  The main
output group SHOULD have the main input group as a pg:source.

"""^^lv2:Markdown .

pg:group
    lv2:documentation """

Indicates that this port is a part of a group of ports on the plugin.  The port
should also have an lv2:designation property to define its designation within
that group.

"""^^lv2:Markdown .

pg:DiscreteGroup
    lv2:documentation """

These groups are divided into channels where each represents a particular
speaker location.  The position of sound in one of these groups depends on a
particular speaker configuration.

"""^^lv2:Markdown .

pg:AmbisonicGroup
    lv2:documentation """

These groups are divided into channels which together represent a position in
an abstract n-dimensional space. The position of sound in one of these groups
does not depend on a particular speaker configuration; a decoder can be used to
convert an ambisonic stream for any speaker configuration.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"ui",
{
juce::lv2::BundleResource
{
"ui.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix ui: <http://lv2plug.in/ns/extensions/ui#> .

<http://lv2plug.in/ns/extensions/ui>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 UI" ;
    doap:shortdesc "User interfaces for LV2 plugins." ;
    doap:created "2006-00-00" ;
    doap:developer <http://lv2plug.in/ns/meta#larsl> ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "2.22" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add ui:requestValue feature."
            ] , [
                rdfs:label "Add ui:scaleFactor, ui:foregroundColor, and ui:backgroundColor properties."
            ] , [
                rdfs:label "Deprecate ui:binary."
            ]
        ]
    ] , [
        doap:revision "2.20" ;
        doap:created "2015-07-25" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Improve documentation."
            ] , [
                rdfs:label "Add missing property labels."
            ]
        ]
    ] , [
        doap:revision "2.18" ;
        doap:created "2014-08-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.10.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add show interface so UIs can gracefully degrade to separate windows if hosts can not use their widget directly."
            ] , [
                rdfs:label "Fix identifier typos in documentation."
            ]
        ]
    ] , [
        doap:revision "2.16" ;
        doap:created "2014-01-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.8.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix LV2_UI_INVALID_PORT_INDEX identifier in documentation."
            ]
        ]
    ] , [
        doap:revision "2.14" ;
        doap:created "2013-03-18" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.6.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add idle interface so native UIs and foreign toolkits can drive their event loops."
            ] , [
                rdfs:label "Add ui:updateRate property."
            ]
        ]
    ] , [
        doap:revision "2.12" ;
        doap:created "2012-12-01" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix incorrect linker flag in ui:makeSONameResident documentation."
            ]
        ]
    ] , [
        doap:revision "2.10" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add types for WindowsUI, CocoaUI, and Gtk3UI."
            ] , [
                rdfs:label "Use consistent label style."
            ] , [
                rdfs:label "Add missing LV2_SYMBOL_EXPORT declaration for lv2ui_descriptor prototype."
            ]
        ]
    ] , [
        doap:revision "2.8" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add ui:parent and ui:resize."
            ] , [
                rdfs:label "Add support for referring to ports by symbol."
            ] , [
                rdfs:label "Add ui:portMap for accessing ports by symbol, allowing for UIs to be distributed separately from plugins."
            ] , [
                rdfs:label "Add port protocols and a dynamic notification subscription mechanism, for more flexible communication, and audio port metering without control port kludges."
            ] , [
                rdfs:label "Add touch feature to notify the host that the user has grabbed a control."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "2.4" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-ui-2.4.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Deprecate ui:makeSONameResident."
            ] , [
                rdfs:label "Add Qt4 and X11 widget types."
            ] , [
                rdfs:label "Install header to URI-based system path."
            ] , [
                rdfs:label "Add pkg-config file."
            ] , [
                rdfs:label "Make ui.ttl a valid OWL 2 DL ontology."
            ]
        ]
    ] , [
        doap:revision "2.2" ;
        doap:created "2011-05-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-ui-2.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system (for installation)."
            ] , [
                rdfs:label "Convert documentation to HTML and use lv2:documentation."
            ] , [
                rdfs:label "Use lv2:Specification to be discovered as an extension."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2010-10-06" ;
        doap:file-release <http://lv2plug.in/spec/lv2-ui-2.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension makes it possible to create user interfaces for LV2 plugins.

UIs are implemented as an LV2UI_Descriptor loaded via lv2ui_descriptor() in a
shared library, and are distributed in bundles just like plugins.

UIs are associated with plugins in data:

    :::turtle
    @prefix ui: <http://lv2plug.in/ns/extensions/ui#> .

    <http://my.plugin>   ui:ui      <http://my.pluginui> .
    <http://my.pluginui> a          ui:X11UI ;
                         lv2:binary <myui.so> .

where `http://my.plugin` is the URI of the plugin, `http://my.pluginui` is the
URI of the plugin UI and `myui.so` is the relative URI to the shared object
file.

While it is possible to have the plugin UI and the plugin in the same shared
object file, it is a good idea to keep them separate so that hosts can avoid
loading the UI code if they do not need it.  A UI MUST specify its class in the
RDF data (`ui:X11UI` in the above example).  The class defines what type the UI
is, for example what graphics toolkit it uses.  Any type of UI class can be
defined separately from this extension.

It is possible to have multiple UIs for the same plugin, or to have the UI for
a plugin in a different bundle from the actual plugin.  This allows plugin UIs
to be written independently.

Note that the process that loads the shared object file containing the UI code
and the process that loads the shared object file containing the actual plugin
implementation are not necessarily the same process (and not even necessarily
on the same machine).  This means that plugin and UI code MUST NOT use
singletons and global variables and expect them to refer to the same objects in
the UI and the actual plugin. The function callback interface defined in this
header is the only method of communication between UIs and plugin instances
(extensions may define more, though this is discouraged unless absolutely
necessary since the significant benefits of network transparency and
serialisability are lost).

UI functionality may be extended via features, much like plugins:

    :::turtle
    <http://my.pluginui> lv2:requiredFeature <http://my.feature> .
    <http://my.pluginui> lv2:optionalFeature <http://my.feature> .

The rules for a UI with a required or optional feature are identical to those
of lv2:Plugin instances: if a UI declares a feature as required, the host is
NOT allowed to load it unless it supports that feature; and if it does support
a feature, it MUST pass an appropriate LV2_Feature struct to the UI's
instantiate() method.  This extension defines several standard features for
common functionality.

UIs written to this specification do not need to be thread-safe.  All functions
may only be called in the <q>UI thread</q>.  There is only one UI thread (for
too)lv2ttl" R"lv2ttl(lkits, the one the UI main loop runs in).  There is no requirement that a
<q>UI</q> actually be a graphical widget.

Note that UIs are completely separate from plugins.  From the plugin's
perspective, control from a UI is indistinguishable from any other control, as
it all occcurs via ports.

"""^^lv2:Markdown .

ui:GtkUI
    lv2:documentation """

The host must guarantee that the Gtk+ 2 library has been initialised and the
Glib main loop is running before the UI is instantiated.  Note that this UI
type is not suitable for binary distribution since multiple versions of Gtk can
not be used in the same process.

"""^^lv2:Markdown .

ui:Gtk3UI
    lv2:documentation """

The host must guarantee that the Gtk+ 3 library has been initialised and the
Glib main loop is running before the UI is instantiated.  Note that this UI
type is not suitable for binary distribution since multiple versions of Gtk can
not be used in the same process.

"""^^lv2:Markdown .

ui:Qt4UI
    lv2:documentation """

The host must guarantee that the Qt4 library has been initialised and the Qt4
main loop is running before the UI is instantiated.  Note that this UI type is
not suitable for binary distribution since multiple versions of Qt can not be
used in the same process.

"""^^lv2:Markdown .

ui:Qt5UI
    lv2:documentation """

The host must guarantee that the Qt5 library has been initialised and the Qt5
main loop is running before the UI is instantiated.  Note that this UI type is
not suitable for binary distribution since multiple versions of Qt can not be
used in the same process.

"""^^lv2:Markdown .

ui:X11UI
    lv2:documentation """

Note that the LV2UI_Widget for this type of UI is not a pointer, but should be
interpreted directly as an X11 `Window` ID.  This is the native UI type on most
POSIX systems.

"""^^lv2:Markdown .

ui:WindowsUI
    lv2:documentation """

Note that the LV2UI_Widget for this type of UI is not a pointer, but should be
interpreted directly as a `HWND`.  This is the native UI type on Microsoft
Windows.

"""^^lv2:Markdown .

ui:CocoaUI
    lv2:documentation """

This is the native UI type on Mac OS X.

"""^^lv2:Markdown .

ui:binary
    lv2:documentation """

This property is redundant and deprecated: new UIs should use lv2:binary
instead, however hosts must still support ui:binary.

"""^^lv2:Markdown .

ui:makeSONameResident
    lv2:documentation """

This feature was intended to support UIs that link against toolkit libraries
which may not be unloaded during the lifetime of the host.  This is better
achieved by using the appropriate flags when linking the UI, for example `gcc
-Wl,-z,nodelete`.

"""^^lv2:Markdown .

ui:noUserResize
    lv2:documentation """

If a UI has this feature, it indicates that it does not make sense to let the
user resize the main widget, and the host should prevent that.  This feature
may not make sense for all UI types.  The data pointer for this feature should
always be set to NULL.

"""^^lv2:Markdown .

ui:fixedSize
    lv2:documentation """

If a UI has this feature, it indicates the same thing as ui:noUserResize, and
additionally that the UI will not resize itself on its own.  That is, the UI
will always remain the same size.  This feature may not make sense for all UI
types.  The data pointer for this feature should always be set to NULL.

"""^^lv2:Markdown .

ui:scaleFactor
    lv2:documentation """

HiDPI (High Dots Per Inch) displays have a high resolution on a relatively
small form factor.  Many systems use a scale factor to compensate for this, so
for example, a scale factor of 2 means things are drawn twice as large as
normal.

Hosts can pass this as an option to UIs to communicate this information, so
that the UI can draw at an appropriate scale.

"""^^lv2:Markdown .

ui:backgroundColor
    lv2:documentation """

The background color of the host's UI.  The host can pass this as an option so
that UIs can integrate nicely with the host window around it.

Hosts should pass this as an option to UIs with an integer RGBA32 color value.
If the value is a 32-bit integer, it is guaranteed to be in RGBA32 format, but
the UI must check the value type and not assume this, to allow for other types
of color in the future.

"""^^lv2:Markdown .

ui:foregroundColor
    lv2:documentation """

The foreground color of the host's UI.  The host can pass this as an option so
that UIs can integrate nicely with the host window around it.

Hosts should pass this as an option to UIs with an integer RGBA32 color value.
If the value is a 32-bit integer, it is guaranteed to be in RGBA32 format, but
the UI must check the value type and not assume this, to allow for other types
of color in the future.

"""^^lv2:Markdown .

ui:parent
    lv2:documentation """

This feature can be used to pass a parent that the UI should be a child of.
The format of data pointer of this feature is determined by the UI type, and is
generally the same type as the LV2UI_Widget that the UI would return.  For
example, for a ui:X11UI, the parent should be a `Window`.  This is particularly
useful for embedding, where the parent often must be known at construction time
for embedding to work correctly.

UIs should not _require_ this feature unless it is necessary for them to work
at all, but hosts should provide it whenever possible.

"""^^lv2:Markdown .

ui:PortNotification
    lv2:documentation """

This describes which ports the host must send notifications to the UI about.
The port must be specific either by index, using the ui:portIndex property, or
symbol, using the lv2:symbol property.  Since port indices are not guaranteed
to be stable, using the symbol is recommended, and the inde MUST NOT be used
except by UIs that are shipped in the same bundle as the corresponding plugin.

"""^^lv2:Markdown .

ui:portNotification
    lv2:documentation """

Specifies that a UI should receive notifications about changes to a particular
port's value via LV2UI_Descriptor::port_event().

For example:

    :::turtle
    eg:ui
        a ui:X11UI ;
        ui:portNotification [
            ui:plugin eg:plugin ;
            lv2:symbol "gain" ;
            ui:protocol ui:floatProtocol
        ] .

"""^^lv2:Markdown .

ui:notifyType
    lv2:documentation """

Specifies a particular type that the UI should be notified of.

This is useful for message-based ports where several types of data can be
present, but only some are interesting to the UI.  For example, if UI control
is multiplexed in the same port as MIDI, this property can be used to ensure
that only the relevant events are forwarded to the UI, and not potentially high
frequency MIDI data.

"""^^lv2:Markdown .

ui:resize
    lv2:documentation """

This feature corresponds to the LV2UI_Resize struct, which should be passed
with the URI LV2_UI__resize.  This struct may also be provided by the UI as
extension data using the same URI, in which case it is used by the host to
request that the UI change its size.

"""^^lv2:Markdown .

ui:portMap
    lv2:documentation """

This makes it possible to implement and distribute UIs separately from the
plugin binaries they control.

This feature corresponds to the LV2UI_Port_Index struct, which should be passed
with the URI LV2_UI__portIndex.

"""^^lv2:Markdown .

ui:portSubscribe
    lv2:documentation """

This makes it possible for a UI to explicitly request a particular style of
update from a port at run-time, in a more flexible and powerful way than
listing subscriptions statically allows.

This feature corresponds to the LV2UI_Port_Subscribe struct, which should be
passed with the URI LV2_UI__portSubscribe.

"""^^lv2:Markdown .

ui:touch
    lv2:documentation """

This is useful for automation, so the host can allow the user to take control
of a port, even if that port would otherwise be automated (much like grabbing a
physical motorised fader).

It can also be used for MIDI learn or in any other situation where the host
needs to do something with a particular control and it would be convenient for
the user to select it directly from the plugin UI.

Thi)lv2ttl" R"lv2ttl(s feature corresponds to the LV2UI_Touch struct, which should be passed with
the URI LV2_UI__touch.

"""^^lv2:Markdown .

ui:requestValue
    lv2:documentation """

This allows a plugin UI to request a new parameter value using the host's UI,
for example by showing a dialog or integrating with the host's built-in content
browser.  This should only be used for complex parameter types where the plugin
UI is not capable of showing the expected native platform or host interface to
choose a value, such as file path parameters.

This feature corresponds to the LV2UI_Request_Value struct, which should be
passed with the URI LV2_UI__requestValue.

"""^^lv2:Markdown .

ui:idleInterface
    lv2:documentation """

To support this feature, the UI should list it as a lv2:optionalFeature or
lv2:requiredFeature in its data, and also as lv2:extensionData.  When the UI's
extension_data() is called with this URI (LV2_UI__idleInterface), it should
return a pointer to an LV2UI_Idle_Interface.

To indicate support, the host should pass a feature to instantiate() with this
URI, with NULL for data.

"""^^lv2:Markdown .

ui:showInterface
    lv2:documentation """

This allows UIs to gracefully degrade to separate windows when the host is
unable to embed the UI widget for whatever reason.  When the UI's
extension_data() is called with this URI (LV2_UI__showInterface), it should
return a pointer to an LV2UI_Show_Interface.

"""^^lv2:Markdown .

ui:PortProtocol
    lv2:documentation """

A PortProtocol MUST define:

Port Type
:   Which plugin port types the buffer type is valid for.

Feature Data
:   What data (if any) should be passed in the LV2_Feature.

A PortProtocol for an output port MUST define:

Update Frequency
:   When the host should call port_event().

Update Format
:   The format of the data in the buffer passed to port_event().

Options
:   The format of the options passed to subscribe() and unsubscribe().

A PortProtocol for an input port MUST define:

Write Format
:   The format of the data in the buffer passed to write_port().

Write Effect
:   What happens when the UI calls write_port().

For an example, see ui:floatProtocol or ui:peakProtocol.

PortProtocol is a subclass of lv2:Feature, so UIs use lv2:optionalFeature and
lv2:requiredFeature to specify which PortProtocols they want to use.

"""^^lv2:Markdown .

ui:floatProtocol
    lv2:documentation """

A protocol for transferring single floating point values.  The rules for this
protocol are:

Port Type
:   lv2:ControlPort

Feature Data
:   None.

Update Frequency
:   The host SHOULD call port_event() as soon as possible when the port value has
    changed, but there are no timing guarantees.

Update Format
:   A single <code>float</code>.

Options
:   None.

Write Format
:   A single <code>float</code>.

Write Effect
:   The host SHOULD set the port to the received value as soon as possible, but
    there is no guarantee that run() actually sees this value.

"""^^lv2:Markdown .

ui:peakProtocol
    lv2:documentation """

This port protocol defines a way for the host to send continuous peak
measurements of the audio signal at a certain port to the UI.  The intended use
is visualisation, for example an animated meter widget that shows the level of
the audio input or output.

A contiguous sequence of audio samples for which a peak value has been computed
is called a _measurement period_.

The rules for this protocol are:

Port Type
:   lv2:AudioPort

Feature Data
:   None.

Update Frequency
:   The host SHOULD call port_event() at regular intervals.  The measurement
    periods used for calls to port_event() for the same port SHOULD be
    contiguous (i.e. the measurement period for one call should begin right
    after the end of the measurement period for the previous call ends) unless
    the UI has removed and re-added the port subscription between those calls.
    However, UIs MUST NOT depend on either the regularity of the calls or the
    contiguity of the measurement periods; hosts may change the call rate or
    skip calls for performance or other reasons.  Measurement periods for
    different calls to port_event() for the same port MUST NOT overlap.

Update Format
:   A single LV2UI_Peak_Data object.

Options
:   None.

Write Format
:   None.

Write Effect
:   None.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/extensions/ui>
    a lv2:Specification ;
    lv2:minorVersion 2 ;
    lv2:microVersion 22 ;
    rdfs:seeAlso <ui.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"ui.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix opts: <http://lv2plug.in/ns/ext/options#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix ui: <http://lv2plug.in/ns/extensions/ui#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/extensions/ui>
    a owl:Ontology ;
    rdfs:label "LV2 UI" ;
    rdfs:comment "User interfaces for LV2 plugins." ;
    owl:imports <http://lv2plug.in/ns/lv2core> ;
    rdfs:seeAlso <ui.h> ,
        <ui.meta.ttl> .

ui:UI
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "User Interface" ;
    rdfs:comment "A UI for an LV2 plugin." .

ui:GtkUI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "GTK2 UI" ;
    rdfs:comment "A UI where the widget is a pointer to a Gtk+ 2.0 GtkWidget." .

ui:Gtk3UI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "GTK3 UI" ;
    rdfs:comment "A UI where the widget is a pointer to a Gtk+ 3.0 GtkWidget." .

ui:Qt4UI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "Qt4 UI" ;
    rdfs:comment "A UI where the widget is a pointer to a Qt4 QWidget." .

ui:Qt5UI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "Qt5 UI" ;
    rdfs:comment "A UI where the widget is a pointer to a Qt5 QWidget." .

ui:X11UI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "X11 UI" ;
    rdfs:comment "A UI where the widget is an X11 Window window ID." .

ui:WindowsUI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "Windows UI" ;
    rdfs:comment "A UI where the widget is a Windows HWND window ID." .

ui:CocoaUI
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf ui:UI ;
    rdfs:label "Cocoa UI" ;
    rdfs:comment "A UI where the widget is a pointer to a NSView." .

ui:ui
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain lv2:Plugin ;
    rdfs:range ui:UI ;
    rdfs:label "user interface" ;
    rdfs:comment "Relates a plugin to a UI that applies to it." .

ui:binary
    a rdf:Property ,
        owl:ObjectProperty ;
    owl:sameAs lv2:binary ;
    owl:deprecated "true"^^xsd:boolean ;
    rdfs:label "binary" ;
    rdfs:comment "The shared library that a UI resides in." .

ui:makeSONameResident
    a lv2:Feature ;
    owl:deprecated "true"^^xsd:boolean ;
    rdfs:label "make SO name resident" ;
    rdfs:comment "UI binary must not be unloaded." .

ui:noUserResize
    a lv2:Feature ;
    rdfs:label "no user resize" ;
    rdfs:comment "Non-resizable UI." .

ui:fixedSize
    a lv2:Feature ;
    rdfs:label "fixed size" ;
    rdfs:comment "Non-resizable UI that will never resize itself." .

ui:scaleFactor
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:range xsd:float ;
    rdfs:label "scale factor" ;
    rdfs:comment "Scale factor for high resolution screens." .

ui:backgroundColor
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:label "background color" ;
    rdfs:comment """The background color of the host's UI.""" .

ui:foregroundColor
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:label "foreground color" ;
    rdfs:comment """The foreground color of the host's UI.""" .

ui:parent
    a lv2:Feature ;
    rdfs:label "parent" ;
    rdfs:comment "The parent for a UI." .

ui:PortNotification
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty ui:plugin ;
        owl:cardinality 1 ;
        rdfs:comment "A PortNotification MUST have exactly one ui:plugin."
    ] ;
    rdfs:label "Port Notification" ;
    rdfs:comment "A description of port updates that a host must send a UI." .

ui:portNotification
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ui:UI ;
    rdfs:range ui:PortNotification ;
    rdfs:label "port notification" ;
    rdfs:comment "Specifies a port notification that is required by a UI." .

ui:plugin
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ui:PortNotification ;
    rdfs:range lv2:Plugin ;
    rdfs:label "plugin" ;
    rdfs:comment "The plugin a portNotification applies to." .

ui:portIndex
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain ui:PortNotification ;
    rdfs:range xsd:decimal ;
    rdfs:label "port index" ;
    rdfs:comment "The index of the port a portNotification applies to." .

ui:notifyType
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ui:PortNotification ;
    rdfs:label "notify type" ;
    rdfs:comment "A particular type that the UI should be notified of." .

ui:resize
    a lv2:Feature ,
        lv2:ExtensionData ;
    rdfs:label "resize" ;
    rdfs:comment """A feature that control of, and notifications about, a UI's size.""" .

ui:portMap
    a lv2:Feature ;
    rdfs:label "port map" ;
    rdfs:comment "A feature for accessing the index of a port by symbol." .

ui:portSubscribe
    a lv2:Feature ;
    rdfs:label "port subscribe" ;
    rdfs:comment "A feature for dynamically subscribing to updates from a port." .

ui:touch
    a lv2:Feature ;
    rdfs:label "touch" ;
    rdfs:comment "A feature to notify that the user has grabbed a port control." .

ui:requestValue
    a lv2:Feature ;
    rdfs:label "request value" ;
    rdfs:comment "A feature to request a parameter value from the user via the host." .

ui:idleInterface
    a lv2:Feature ,
        lv2:ExtensionData ;
    rdfs:label "idle interface" ;
    rdfs:comment "A feature that provides a callback for the host to drive the UI." .

ui:showInterface
    a lv2:ExtensionData ;
    rdfs:label "show interface" ;
    rdfs:comment "An interface for showing and hiding a window for a UI." .

ui:windowTitle
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:range xsd:string ;
    rdfs:label "window title" ;
    rdfs:comment "The title for the window shown by LV2UI_Show_Interface." .

ui:updateRate
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:range xsd:float ;
    rdfs:label "update rate" ;
    rdfs:comment "The target rate, in Hz, to send updates to the UI." .

ui:protocol
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ui:PortNotification ;
    rdfs:range ui:PortProtocol ;
    rdfs:label "protocol" ;
    rdfs:comment "The protocol to be used for this notification." .

ui:PortProtocol
    a rdfs:Class ;
    rdfs:subClassOf lv2:Feature ;
    rdfs:label "Port Protocol" ;
    rdfs:comment "A method to communicate port data between a UI and plugin." .

ui:floatProtocol
    a ui:PortProtocol ;
    rdfs:label "float protocol" ;
    rdfs:comment "A protocol for transferring single floating point values." .

ui:peakProtocol
    a ui:PortProtocol ;
    rdfs:label "peak protocol" ;
    rdfs:comment "A protocol for sending continuous peak measurements of an audio signal." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"options",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/options>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 4 ;
    rdfs:seeAlso <options.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"options.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix opts: <http://lv2plug.in/ns/ext/options#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/options>
    a owl:Ontology ;
    rdfs:label "LV2 Options" ;
    rdfs:comment "Runtime options for LV2 plugins and UIs." ;
    rdfs:seeAlso <options.h> ,
        <options.meta.ttl> .

opts:Option
    a rdfs:Class ;
    rdfs:label "Option" ;
    rdfs:subClassOf rdf:Property ;
    rdfs:comment "A value for a static option passed to an instance." .

opts:interface
    a lv2:ExtensionData ;
    rdfs:label "interface" ;
    rdfs:comment "An interface for dynamically setting and getting options." .

opts:options
    a lv2:Feature ;
    rdfs:label "options" ;
    rdfs:comment "The feature used to provide options to an instance." .

opts:requiredOption
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range rdf:Property ;
    rdfs:label "required option" ;
    rdfs:comment "An option required by the instance to function at all." .

opts:supportedOption
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range rdf:Property ;
    rdfs:label "supported option" ;
    rdfs:comment "An option supported or by the instance." .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"options.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix opts: <http://lv2plug.in/ns/ext/options#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/options>
    a doap:Project ;
    doap:name "LV2 Options" ;
    doap:shortdesc "Runtime options for LV2 plugins and UIs." ;
    doap:created "2012-08-20" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.4" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Relax range of opts:requiredOption and opts:supportedOption"
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2013-01-10" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Set the range of opts:requiredOption and opts:supportedOption to opts:Option."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a facility for <q>options</q>, which are values the host
passes to a plugin or UI at run time.

There are two facilities for passing options to an instance: opts:options
allows passing options at instantiation time, and the opts:interface interface
allows options to be dynamically set and retrieved after instantiation.

Note that this extension is only for allowing hosts to configure plugins, and
is not a <q>live</q> control mechanism.  For real-time control, use event-based
control via an atom:AtomPort with an atom:Sequence buffer.

Instances may indicate they require an option with the opts:requiredOption
property, or that they optionally support an option with the
opts:supportedOption property.

"""^^lv2:Markdown .

opts:Option
    lv2:documentation """

It is not required for a property to explicitly be an Option in order to be
used as such.  However, properties which are primarily intended for use as
options, or are at least particularly useful as options, should be explicitly
given this type for documentation purposes, and to assist hosts in discovering
option definitions.

"""^^lv2:Markdown .

opts:interface
    lv2:documentation """

An interface (LV2_Options_Interface) for dynamically setting and getting
options.  Note that this is intended for use by the host for configuring
plugins only, and is not a <q>live</q> plugin control mechanism.

The plugin data file should advertise this interface like so:

    :::turtle
    @prefix opts: <http://lv2plug.in/ns/ext/options#> .

    <plugin>
        a lv2:Plugin ;
        lv2:extensionData opts:interface .

"""^^lv2:Markdown .

opts:options
    lv2:documentation """

To implement this feature, hosts MUST pass an LV2_Feature to the appropriate
instantiate method with this URI and data pointed to an array of
LV2_Options_Option terminated by an element with both key and value set to
zero.  The instance should cast this data pointer to `const
LV2_Options_Option*` and scan the array for any options of interest.  The
instance MUST NOT modify the options array in any way.

Note that requiring this feature may reduce the number of compatible hosts.
Unless some options are strictly required by the instance, this feature SHOULD
be listed as an lv2:optionalFeature.

"""^^lv2:Markdown .

opts:requiredOption
    lv2:documentation """

The host MUST pass a value for the specified option via opts:options during
instantiation.

Note that use of this property may reduce the number of compatible hosts.
Wherever possible, it is better to list options with opts:supportedOption and
fall back to a reasonable default value if it is not provided.

"""^^lv2:Markdown .

opts:supportedOption
    lv2:documentation """

The host SHOULD provide a value for the specified option if one is known, or
provide the user an opportunity to specify one if possible.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"resize-port",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/resize-port>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 0 ;
    rdfs:seeAlso <resize-port.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"resize-port.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix rsz: <http://lv2plug.in/ns/ext/resize-port#> .

<http://lv2plug.in/ns/ext/resize-port>
    a doap:Project ;
    doap:name "LV2 Resize Port" ;
    doap:shortdesc "Dynamically sized LV2 port buffers." ;
    doap:created "2007-00-00" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a feature, rsz:resize, which allows plugins to
dynamically resize their output port buffers.

In addition to the dynamic feature, there are properties which describe the
space required for a particular port buffer which can be used statically in
data files.

"""^^lv2:Markdown .

rsz:resize
    lv2:documentation """

A feature to resize output port buffers in LV2_Plugin_Descriptor::run().

To support this feature, the host must pass an LV2_Feature to the plugin's
instantiate method with URI LV2_RESIZE_PORT__resize and a pointer to a
LV2_Resize_Port_Resize structure.  This structure provides a resize_port
function which plugins may use to resize output port buffers as necessary.

"""^^lv2:Markdown .

rsz:asLargeAs
    lv2:documentation """

Indicates that a port requires at least as much buffer space as the port with
the given symbol on the same plugin instance.  This may be used for any ports,
but is generally most useful to indicate an output port must be at least as
large as some input port (because it will copy from it).  If a port is
asLargeAs several ports, it is asLargeAs the largest such port (not the sum of
those ports' sizes).

The host guarantees that whenever an ObjectPort's run method is called, any
output `O` that is rsz:asLargeAs an input `I` is connected to a buffer large
enough to copy `I`, or `NULL` if the port is lv2:connectionOptional.

"""^^lv2:Markdown .

rsz:minimumSize
    lv2:documentation """

Indicates that a port requires a buffer at least this large, in bytes.  Any
host that supports the resize-port feature MUST connect any port with a
minimumSize specified to a buffer at least as large as the value given for this
property.  Any host, especially those that do NOT support dynamic port
resizing, SHOULD do so or reduced functionality may result.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"resize-port.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix rsz: <http://lv2plug.in/ns/ext/resize-port#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/resize-port>
    a owl:Ontology ;
    rdfs:label "LV2 Resize Port" ;
    rdfs:comment "Dynamically sized LV2 port buffers." ;
    rdfs:seeAlso <resize-port.h> ,
        <resize-port.meta.ttl> .

rsz:resize
    a lv2:Feature ;
    rdfs:label "resize" ;
    rdfs:comment "A feature for resizing output port buffers." .

rsz:asLargeAs
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain lv2:Port ;
    rdfs:range lv2:Symbol ;
    rdfs:label "as large as" ;
    rdfs:comment "Port that this port must have at least as much buffer space as." .

rsz:minimumSize
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain lv2:Port ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "minimum size" ;
    rdfs:comment "Minimum buffer size required by a port, in bytes." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"core",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/lv2core>
    a lv2:Specification ;
    lv2:minorVersion 18 ;
    lv2:microVersion 0 ;
    rdfs:seeAlso <lv2core.ttl> .

<http://lv2plug.in/ns/lv2>
    a doap:Project ;
    rdfs:seeAlso <meta.ttl> ,
        <people.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix meta: <http://lv2plug.in/ns/meta#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://opensource.org/licenses/isc>
    rdf:value """
Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted, provided that the above copyright notice and this permission notice appear in all copies.

THIS SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
""" .

<http://lv2plug.in/ns/lv2>
    a doap:Project ;
    lv2:symbol "lv2" ;
    rdfs:label "LV2" ;
    rdfs:comment "The LV2 Plugin Interface Project." ;
    doap:name "LV2" ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:shortdesc "The LV2 Plugin Interface Project." ;
    doap:description "LV2 is a plugin standard for audio systems. It defines a minimal yet extensible C API for plugin code and a format for plugin bundles" ;
    doap:created "2006-05-10" ;
    doap:homepage <http://lv2plug.in/> ;
    doap:mailing-list <http://lists.lv2plug.in/listinfo.cgi/devel-lv2plug.in> ;
    doap:programming-language "C" ;
    doap:repository [
        a doap:SVNRepository ;
        doap:location <http://lv2plug.in/repo>
    ] ;
    doap:developer <http://drobilla.net/drobilla#me> ,
        <http://plugin.org.uk/swh.xrdf#me> ;
    doap:helper meta:larsl ,
        meta:bmwiedemann ,
        meta:gabrbedd ,
        meta:daste ,
        meta:kfoltman ,
        meta:paniq ;
    doap:release [
        doap:revision "1.18.2" ;
        doap:created "2021-01-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "eg-sampler: Save and restore gain parameter value."
            ] , [
                rdfs:label "Various code cleanups and infrastructure improvements."
            ]
        ]
    ] , [
        doap:revision "1.18.0" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Improve documentation."
            ] , [
                rdfs:label "Separate extended documentation from primary data."
            ]
        ]
    ] , [
        doap:revision "1.16.0" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add core/attributes.h utility header."
            ] , [
                rdfs:label "eg-sampler: Add waveform display to UI."
            ] , [
                rdfs:label "eg-midigate: Respond to \"all notes off\" MIDI message."
            ] , [
                rdfs:label "Simplify use of lv2specgen."
            ] , [
                rdfs:label "Add lv2_validate utility."
            ] , [
                rdfs:label "Install headers to simpler paths."
            ] , [
                rdfs:label "Aggressively deprecate uri-map and event extensions."
            ] , [
                rdfs:label "Upgrade build system and fix building with Python 3.7."
            ]
        ]
    ] , [
        doap:revision "1.14.0" ;
        doap:created "2016-09-19" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label """eg-scope: Don't feed back UI state updates."""
            ] , [
                rdfs:label "eg-sampler: Fix handling of state file paths."
            ] , [
                rdfs:label "eg-sampler: Support thread-safe state restoration."
            ]
        ]
    ] , [
        doap:revision "1.12.0" ;
        doap:created "2015-04-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.12.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "eg-sampler: Support patch:Get, and request initial state from UI."
            ] , [
                rdfs:label "eg-sampler: Add gain parameter."
            ] , [
                rdfs:label "Fix merging of version histories in specification documentation."
            ] , [
                rdfs:label "Improve API documentation."
            ] , [
                rdfs:label "Simplify property restrictions by removing redundancy."
            ]
        ]
    ] , [
        doap:revision "1.10.0" ;
        doap:created "2014-08-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.10.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "lv2specgen: Display deprecated warning on classes marked owl:deprecated."
            ] , [
                rdfs:label "Fix -Wconversion warnings in headers."
            ] , [
                rdfs:label "Upgrade to waf 1.7.16."
            ]
        ]
    ] , [
        doap:revision "1.8.0" ;
        doap:created "2014-01-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.8.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add scope example plugin from Robin Gareus."
            ] , [
                rdfs:label "lv2specgen: Fix links to externally defined terms."
            ] , [
                rdfs:label "Install lv2specgen for use by other projects."
            ]
        ]
    ] , [
        doap:revision "1.6.0" ;
        doap:created "2013-08-09" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.6.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix port indices of metronome example."
            ] , [
                rdfs:label "Fix lv2specgen usage from command line."
            ] , [
                rdfs:label "Upgrade to waf 1.7.11."
            ]
        ]
    ] , [
        doap:revision "1.4.0" ;
        doap:created "2013-02-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add metronome example plugin to demonstrate sample accurate tempo sync."
            ] , [
                rdfs:label "Generate book-style HTML documentation from example plugins."
            ]
        ]
    ] , [
        doap:revision "1.2.0" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Move all project metadata for extensions (e.g. change log) to separate files to spare hosts from loading them during discovery."
            ] , [
                rdfs:label "Use stricter datatype definitions conformant with the XSD and OWL specifications for better validation."
            ]
        ]
    ] , [
        doap:revision "1.0.0" ;
        doap:created "2012-04-16" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label """Initial release as a unified project.  Projects can now simply depend on the pkg-config package 'lv2' for all official LV2 APIs."""
            ] , [
                rdfs:label "New extensions: atom, log, parameters, patch, port-groups, port-props, resize-port, state, time, worker."
            ]
        ]
    ] .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"people.ttl",
R"lv2ttl(@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix meta: <http://lv2plug.in/ns/meta#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://drobilla.net/drobilla#me>
    a foaf:Person ;
    foaf:name "David Robillard" ;
    foaf:mbox <mailto:d@drobilla.net> ;
    rdfs:seeAlso <http://drobilla.net/drobilla> .

<http://plugin.org.uk/swh.xrdf#me>
    a foaf:Person ;
    foaf:name "Steve Harris" ;
    foaf:mbox <mailto:steve@plugin.org.uk> ;
    rdfs:seeAlso <http://plugin.org.uk/swh.xrdf> .

meta:larsl
    a foaf:Person ;
    foaf:name "Lars Luthman" ;
    foaf:mbox <mailto:lars.luthman@gmail.com> .

meta:gabrbedd
    a foaf:Person ;
    foaf:name "Gabriel M. Beddingfield" ;
    foaf:mbox <mailto:gabrbedd@gmail.com> .

meta:daste
    a foaf:Person ;
    foaf:name """Stefano D'Angelo""" ;
    foaf:mbox <mailto:zanga.mail@gmail.com> .

meta:kfoltman
    a foaf:Person ;
    foaf:name "Krzysztof Foltman" ;
    foaf:mbox <mailto:wdev@foltman.com> .

meta:paniq
    a foaf:Person ;
    foaf:name "Leonard Ritter" ;
    foaf:mbox <mailto:paniq@paniq.org> .

meta:harry
    a foaf:Person ;
    foaf:name "Harry van Haaren" ;
    foaf:mbox <harryhaaren@gmail.com> .

meta:bmwiedemann
    a foaf:Person ;
    foaf:name "Bernhard M. Wiedemann" ;
    foaf:mbox <bwiedemann@suse.de> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"lv2core.meta.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/lv2core>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2" ;
    doap:homepage <http://lv2plug.in> ;
    doap:created "2004-04-21" ;
    doap:shortdesc "An extensible open standard for audio plugins" ;
    doap:programming-language "C" ;
    doap:developer <http://plugin.org.uk/swh.xrdf#me> ,
        <http://drobilla.net/drobilla#me> ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "18.0" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2:Markdown datatype."
            ] , [
                rdfs:label "Deprecate lv2:reportsLatency."
            ]
        ]
    ] , [
        doap:revision "16.0" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2:MIDIPlugin class."
            ] , [
                rdfs:label "Rework port restrictions so that presets can be validated."
            ]
        ]
    ] , [
        doap:revision "14.0" ;
        doap:created "2016-09-18" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2_util.h with lv2_features_data() and lv2_features_query()."
            ] , [
                rdfs:label "Add lv2:enabled designation."
            ]
        ]
    ] , [
        doap:revision "12.4" ;
        doap:created "2015-04-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.12.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Relax domain of lv2:minimum lv2:maximum and lv2:default so they can be used to describe properties/parameters as well."
            ] , [
                rdfs:label "Add extern C and visibility attribute to LV2_SYMBOL_EXPORT."
            ] , [
                rdfs:label "Add lv2:isSideChain port property."
            ]
        ]
    ] , [
        doap:revision "12.2" ;
        doap:created "2014-08-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.10.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Clarify lv2_descriptor() and lv2_lib_descriptor() documentation."
            ]
        ]
    ] , [
        doap:revision "12.0" ;
        doap:created "2014-01-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.8.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2:prototype for property inheritance."
            ]
        ]
    ] , [
        doap:revision "10.0" ;
        doap:created "2013-02-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2:EnvelopePlugin class."
            ] , [
                rdfs:label "Add lv2:control for designating primary event-based control ports."
            ] , [
                rdfs:label "Set range of lv2:designation to lv2:Designation."
            ] , [
                rdfs:label "Make lv2:Parameter rdfs:subClassOf rdf:Property."
            ] , [
                rdfs:label "Reserve minor version 0 for unstable development plugins."
            ]
        ]
    ] , [
        doap:revision "8.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "8.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix LV2_SYMBOL_EXPORT and lv2_descriptor prototype for Windows."
            ] , [
                rdfs:label "Add metadata concept of a designation, a channel or parameter description which can be assigned to ports for more intelligent use by hosts."
            ] , [
                rdfs:label "Add new discovery API which allows libraries to read bundle files during discovery, makes library construction/destruction explicit, and adds extensibility to prevent future breakage."
            ] , [
                rdfs:label "Relax the range of lv2:index so it can be used for things other than ports."
            ] , [
                rdfs:label "Remove lv2:Resource, which turned out to be meaningless."
            ] , [
                rdfs:label "Add lv2:CVPort."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "6.0" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2core-6.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Rename core.lv2 and lv2.ttl to lv2core.lv2 and lv2core.ttl to adhere to modern conventions."
            ] , [
                rdfs:label "Add lv2:extensionData and lv2:ExtensionData for plugins to indicate that they support some URI for extension_data()."
            ] , [
                rdfs:label "Remove lv2config in favour of the simple convention that specifications install headers to standard URI-based paths."
            ] , [
                rdfs:label "Switch to the ISC license, a simple BSD-style license (with permission of all contributors to lv2.h and its ancestor, ladspa.h)."
            ] , [
                rdfs:label "Make lv2core.ttl a valid OWL 2 DL ontology."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "4.0" ;
        doap:created "2011-03-18" ;
        doap:file-release <http://lv2plug.in/spec/lv2core-4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Make doap:license suggested, but not required (for wrappers)."
            ] , [
                rdfs:label "Define lv2:binary (MUST be in manifest.ttl)."
            ] , [
                rdfs:label "Define lv2:minorVersion and lv2:microVersion (MUST be in manifest.ttl)."
            ] , [
                rdfs:label "Define lv2:documentation and use it to document lv2core."
            ] , [
                rdfs:label "Add lv2:FunctionPlugin and lv2:ConstantPlugin classes."
            ] , [
                rdfs:label "Move lv2:AmplifierPlugin under lv2:DynamicsPlugin."
            ] , [
                rdfs:label "Loosen domain of lv2:optionalFeature and lv2:requiredFeature (to allow re-use in extensions)."
            ] , [
                rdfs:label "Add generic lv2:Resource and lv2:PluginBase classes."
            ] , [
                rdfs:label "Fix definition of lv2:minimum etc. (used for values, not scale points)."
            ] , [
                rdfs:label "More precisely define properties with OWL."
            ] , [
                rdfs:label "Move project metadata to manifest."
            ] , [
                rdfs:label "Add lv2:enumeration port property."
            ] , [
                rdfs:label "Define run() pre-roll special case (sample_count == 0)."
            ]
        ]
    ] , [
        doap:revision "3.0" ;
        doap:created "2008-11-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2core-3.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Require that serialisations refer to ports by symbol rather than index."
            ] , [
                rdfs:label "Minor stylistic changes to lv2.ttl."
            ] , [
                rdfs:label "No header changes."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2008-02-10" ;
        doap:file-release <http://lv2plug.in/spec/lv2core-2.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

LV2 is an interface for writing audio plugins in C or compatible languages,
which can be dynamically loaded into many _host_ applications.  This core
specification is simple and minimal, but is designed so that _extensions_ can
be defined to add more advanced features, making it possible to implement
nearly any feature.

LV2 maintains a strong distinction between code and data.  Plugin code is in a
shared library, while data is in a companion data file written in
[Turtle](https://www.w3.org/TR/turtle/).  Code, data, and any other resources
(such as wav)lv2ttl" R"lv2ttl(eforms) are shipped together in a bundle directory.  The code
contains only the executable portions of the plugin.  All other data is
provided in the data file(s).  This makes plugin data flexible and extensible,
and allows the host to do everything but run the plugin without loading or
executing any code.  Among other advantages, this makes hosts more robust
(broken plugins can't crash a host during discovery) and allows generic tools
written in any language to work with LV2 data.  The LV2 specification itself is
distributed in a similar way.

An LV2 plugin library is suitable for dynamic loading (for example with
`dlopen()`) and provides one or more plugin descriptors via `lv2_descriptor()`
or `lv2_lib_descriptor()`.  These can be instantiated to create plugin
instances, which can be run directly on data or connected together to perform
advanced signal processing tasks.

Plugins communicate via _ports_, which can transmit any type of data.  Data is
processed by first connecting each port to a buffer, then repeatedly calling
the `run()` method to process blocks of data.

This core specification defines two types of port, equivalent to those in
[LADSPA](http://www.ladspa.org/), lv2:ControlPort and lv2:AudioPort, as well as
lv2:CVPort which has the same format as an audio port but is interpreted as
non-audible control data.  Audio ports contain arrays with one `float` element
per sample, allowing a block of audio to be processed in a single call to
`run()`.  Control ports contain single `float` values, which are fixed and
valid for the duration of the call to `run()`.  Thus the _control rate_ is
determined by the block size, which is controlled by the host (and not
necessarily constant).

### Threading Rules

To faciliate use in multi-threaded programs, LV2 functions are partitioned into
several threading classes:

| Discovery Class                  | Instantiation Class           | Audio Class                    |
|----------------------------------|-------------------------------|------------------------------- |
| lv2_descriptor()                 | LV2_Descriptor::instantiate() | LV2_Descriptor::run()          |
| lv2_lib_descriptor()             | LV2_Descriptor::cleanup()     | LV2_Descriptor::connect_port() |
| LV2_Descriptor::extension_data() | LV2_Descriptor::activate()    |                                |
|                                  | LV2_Descriptor::deactivate()  |                                |

Hosts MUST guarantee that:

 * A function in any class is never called concurrently with another function
   in that class.

 * A _Discovery_ function is never called concurrently with any other fuction
   in the same shared object file.

 * An _Instantiation_ function for an instance is never called concurrently
   with any other function for that instance.

Any simultaneous calls that are not explicitly forbidden by these rules are
allowed. For example, a host may call `run()` for two different plugin
instances simultaneously.

Plugin functions in any class MUST NOT manipulate any state which might affect
other plugins or the host (beyond the contract of that function), for example
by using non-reentrant global functions.

Extensions to this specification which add new functions MUST declare in which
of these classes the functions belong, define new classes for them, or
otherwise precisely describe their threading rules.

"""^^lv2:Markdown .

lv2:Specification
    lv2:documentation """

An LV2 specification typically contains a vocabulary description, C headers to
define an API, and any other resources that may be useful.  Specifications,
like plugins, are distributed and installed as bundles so that hosts may
discover them.

"""^^lv2:Markdown .

lv2:Markdown
    lv2:documentation """

This datatype is typically used for documentation in
[Markdown](https://daringfireball.net/projects/markdown/syntax) syntax.

Generally, documentation with this datatype should stay as close to readable
plain text as possible, but may use core Markdown syntax for nicer
presentation.  Documentation can assume that basic extensions like codehilite
and tables are available.

"""^^lv2:Markdown .

lv2:documentation
    lv2:documentation """

Relates a Resource to extended documentation.

LV2 specifications are documented using this property with an lv2:Markdown
datatype.

If the value has no explicit datatype, it is assumed to be a valid XHTML Basic
1.1 fragment suitable for use as the content of the `body` element of a page.

XHTML Basic is a W3C Recommendation which defines a simplified subset of XHTML
intended to be reasonable to implement with limited resources, for exampe on
embedded devices. See [XHTML Basic, Section
3](http://www.w3.org/TR/xhtml-basic/#s_xhtmlmodules) for a list of valid tags.

"""^^lv2:Markdown .

lv2:PluginBase
    lv2:documentation """

An abstract plugin-like resource that may not actually be an LV2 plugin, for
example that may not have a lv2:binary.  This is useful for describing things
that share common structure with a plugin, but are not themselves an actul
plugin, such as presets.

"""^^lv2:Markdown .

lv2:Plugin
    lv2:documentation """

To be discovered by hosts, plugins MUST explicitly have an rdf:type of lv2:Plugin
in their bundle's manifest, for example:

    :::turtle
    <http://example.org/my-plugin> a lv2:Plugin .

Plugins should have a doap:name property that is at most a few words in length
using title capitalization, for example <q>Tape Delay Unit</q>.

"""^^lv2:Markdown .

lv2:PortBase
    lv2:documentation """

Similar to lv2:PluginBase, this is an abstract port-like resource that may not
be a fully specified LV2 port.  For example, this is used for preset "ports"
which do not specify an index.

"""^^lv2:Markdown .

lv2:Port
    lv2:documentation """

All LV2 port descriptions MUST have a rdf:type that is one of lv2:Port,
lv2:InputPort or lv2:OutputPort.  Additionally, there MUST be at least one
other rdf:type which more precisely describes type of the port, for example
lv2:AudioPort.

Hosts that do not support a specific port class MUST NOT instantiate the
plugin, unless that port has the lv2:connectionOptional property set.

A port has two identifiers: a (numeric) index, and a (textual) symbol.  The
index can be used as an identifier at run-time, but persistent references to
ports (for example in presets or save files) MUST use the symbol.  Only the
symbol is guaranteed to refer to the same port on all plugins with a given URI,
that is the index for a port may differ between plugin binaries.

"""^^lv2:Markdown .

lv2:AudioPort
    lv2:documentation """

Ports of this type are connected to a buffer of `float` audio samples, which
the host guarantees have `sample_count` elements in any call to
LV2_Descriptor::run().

Audio samples are normalized between -1.0 and 1.0, though there is no
requirement for samples to be strictly within this range.

"""^^lv2:Markdown .

lv2:CVPort
    lv2:documentation """

Ports of this type have the same buffer format as an lv2:AudioPort, except the
buffer represents audio-rate control data rather than audio.  Like a
lv2:ControlPort, a CV port SHOULD have properties describing its value, in
particular lv2:minimum, lv2:maximum, and lv2:default.

Hosts may present CV ports to users as controls in the same way as control
ports.  Conceptually, aside from the buffer format, a CV port is the same as a
control port, so hosts can use all the same properties and expectations.

In particular, this port type does not imply any range, unit, or meaning for
its values.  However, if there is no inherent unit to the values, for example
if the port is used to modulate some other value, then plugins SHOULD use a
normalized range, either from -1.0 to 1.0, or from 0.0 to 1.0.

It is generally safe to connect an audio output to a CV input, but not
vice-versa.  Hosts must take care to prevent data from a CVPort port from being
used as audio.

"""^^lv2:Markdown .

lv2:project
    lv2:documentation """

This property provides a way to )lv2ttl" R"lv2ttl(group plugins and/or related resources.  A
project may have useful metadata common to all plugins (such as homepage,
author, version history) which would be wasteful to list separately for each
plugin.

Grouping via projects also allows users to find plugins in hosts by project,
which is often how they are remembered.  For this reason, a project that
contains plugins SHOULD always have a doap:name.  It is also a good idea for
each plugin and the project itself to have an lv2:symbol property, which allows
nice quasi-global identifiers for plugins, for example `myproj.superamp` which
can be useful for display or fast user entry.

"""^^lv2:Markdown .

lv2:prototype
    lv2:documentation """

This property can be used to <q>include</q> common properties in several
descriptions, serving as a sort of template mechanism.  If a plugin has a
prototype, then the host must load all the properties for the prototype as if
they were properties of the plugin.  That is, if `:plug lv2:prototype :prot`,
then for each triple `:prot p o`, the triple `:plug p o` should be loaded.

This facility is useful for distributing data-only plugins that rely on a
common binary, for example those where the internal state is loaded from some
other file.  Such plugins can refer to a prototype in a template LV2 bundle
which is installed by the corresponding software.

"""^^lv2:Markdown .

lv2:minorVersion
    lv2:documentation """

This, along with lv2:microVersion, is used to distinguish between different
versions of the <q>same</q> resource, for example to load only the bundle with
the most recent version of a plugin.  An LV2 version has a minor and micro
number with the usual semantics:

  * The minor version MUST be incremented when backwards (but not forwards)
    compatible additions are made, for example the addition of a port to a
    plugin.

  * The micro version is incremented for changes which do not affect
    compatibility at all, for example bug fixes or documentation updates.

Note that there is deliberately no major version: all versions with the same
URI are compatible by definition.  Replacing a resource with a newer version of
that resource MUST NOT break anything.  If a change violates this rule, then
the URI of the resource (which serves as the major version) MUST be changed.

Plugins and extensions MUST adhere to at least the following rules:

  * All versions of a plugin with a given URI MUST have the <q>same</q> set of
    mandatory (not lv2:connectionOptional) ports with respect to lv2:symbol and
    rdf:type.  In other words, every port on a particular version is guaranteed
    to exist on a future version with same lv2:symbol and at least those
    rdf:types.

  * New ports MAY be added without changing the plugin URI if and only if they
    are lv2:connectionOptional and the minor version is incremented.

  * The minor version MUST be incremented if the index of any port (identified
    by its symbol) is changed.

  * All versions of a specification MUST be compatible in the sense that an
    implementation of the new version can interoperate with an implementation
    of any previous version.

Anything that depends on a specific version of a plugin (including referencing
ports by index) MUST refer to the plugin by both URI and version.  However,
implementations should be tolerant where possible.

When hosts discover several installed versions of a resource, they SHOULD warn
the user and load only the most recent version.

An odd minor _or_ micro version, or minor version zero, indicates that the
resource is a development version.  Hosts and tools SHOULD clearly indicate
this wherever appropriate.  Minor version zero is a special case for
pre-release development of plugins, or experimental plugins that are not
intended for stable use at all.  Hosts SHOULD NOT expect such a plugin to
remain compatible with any future version.  Where feasible, hosts SHOULD NOT
expose such plugins to users by default, but may provide an option to display
them.

"""^^lv2:Markdown .

lv2:microVersion
    lv2:documentation """

Releases of plugins and extensions MUST be explicitly versioned.  Correct
version numbers MUST always be maintained for any versioned resource that is
published. For example, after a release, if a change is made in the development
version in source control, the micro version MUST be incremented (to an odd
number) to distinguish this modified version from the previous release.

This property describes half of a resource version. For detailed documentation
on LV2 resource versioning, see lv2:minorVersion.

"""^^lv2:Markdown .

lv2:binary
    lv2:documentation """

The value of this property must be the URI of a shared library object,
typically in the same bundle as the data file which contains this property.
The actual type of the library is platform specific.

This is a required property of a lv2:Plugin which MUST be included in the
bundle's `manifest.ttl` file.  The lv2:binary of a lv2:Plugin is the shared
object containing the lv2_descriptor() or lv2_lib_descriptor() function.  This
probably may also be used similarly by extensions to relate other resources to
their implementations (it is not implied that a lv2:binary on an arbitrary
resource is an LV2 plugin library).

"""^^lv2:Markdown .

lv2:appliesTo
    lv2:documentation """

This is primarily intended for discovery purposes: bundles that describe
resources that work with particular plugins (like presets or user interfaces)
SHOULD specify this in their `manifest.ttl` so the host can associate them with
the correct plugin.  For example:

    :::turtle
    <thing>
        a             ext:Thing ;
        lv2:appliesTo <plugin> ;
        rdfs:seeAlso  <thing.ttl> .

Using this pattern is preferable for large amounts of data, since the host may
choose whether/when to load the data.

"""^^lv2:Markdown .

lv2:Symbol
    lv2:documentation """

The first character of a symbol must be one of `_`, `a-z` or `A-Z`, and
subsequent characters may additionally be `0-9`.  This is, among other things,
a valid C identifier, and generally compatible in most contexts which have
restrictions on string identifiers, such as file paths.

"""^^lv2:Markdown .

lv2:symbol
    lv2:documentation """

The value of this property MUST be a valid lv2:Symbol, and MUST NOT have a
language tag.

A symbol is a unique identifier with respect to the parent, for example a
port's symbol is a unique identifiers with respect to its plugin.  The plugin
author MUST change the plugin URI if any port symbol is changed or removed.

"""^^lv2:Markdown .

lv2:name
    lv2:documentation """

Unlike lv2:symbol, this is unrestricted, may be translated, and is not relevant
for compatibility.  The name is not necessarily unique and MUST NOT be used as
an identifier.

"""^^lv2:Markdown .

lv2:shortName
    lv2:documentation """

This is the same as lv2:name, with the additional requirement that the value is
shorter than 16 characters.

"""^^lv2:Markdown .

lv2:Designation
    lv2:documentation """

A designation is metadata that describes the meaning or role of something.  By
assigning a designation to a port using lv2:designation, the port's content
becomes meaningful and can be used more intelligently by the host.

"""^^lv2:Markdown .

lv2:Channel
    lv2:documentation """

A specific channel, for example the <q>left</q> channel of a stereo stream.  A
channel may be audio, or another type such as a MIDI control stream.

"""^^lv2:Markdown .

lv2:Parameter
    lv2:documentation """

A parameter is a designation for a control.

A parameter defines the meaning of a control, not the method of conveying its
value.  For example, a parameter could be controlled via a lv2:ControlPort,
messages, or both.

A lv2:ControlPort can be associated with a parameter using lv2:designation.

"""^^lv2:Markdown .

lv2:designation
    lv2:documentation """

This property is used to give a port's contents a well-defined meaning.  For
example, if a port has the designation `eg:gain`, then the value of that port
re)lv2ttl" R"lv2ttl(presents the `eg:gain` of the plugin instance.

Ports should be given designations whenever possible, particularly if a
suitable designation is already defined.  This allows the host to act more
intelligently and provide a more effective user interface.  For example, if the
plugin has a BPM parameter, the host may automatically set that parameter to
the current tempo.

"""^^lv2:Markdown .

lv2:freeWheeling
    lv2:documentation """

If true, this means that all processing is happening as quickly as possible,
not in real-time.  When free-wheeling there is no relationship between the
passage of real wall-clock time and the passage of time in the data being
processed.

"""^^lv2:Markdown .

lv2:enabled
    lv2:documentation """

If this value is greater than zero, the plugin processes normally.  If this
value is zero, the plugin is expected to bypass all signals unmodified.  The
plugin must provide a click-free transition between the enabled and disabled
(bypassed) states.

Values less than zero are reserved for future use (such as click-free
insertion/removal of latent plugins), and should be treated like zero
(bypassed) by current implementations.

"""^^lv2:Markdown .

lv2:control
    lv2:documentation """

This should be used as the lv2:designation of ports that are used to send
commands and receive responses.  Typically this will be an event port that
supports some protocol, for example MIDI or LV2 Atoms.

"""^^lv2:Markdown .

lv2:Point
    lv2:documentation """

  * A Point MUST have at least one rdfs:label which is a string.

  * A Point MUST have exactly one rdf:value with a type that is compatible with
    the type of the corresponding Port.

"""^^lv2:Markdown .

lv2:default
    lv2:documentation """

The host SHOULD set the port to this value initially, and in any situation
where the port value should be cleared or reset.

"""^^lv2:Markdown .

lv2:minimum
    lv2:documentation """

This is a soft limit: the plugin is required to gracefully accept all values in
the range of a port's data type.

"""^^lv2:Markdown .

lv2:maximum
    lv2:documentation """

This is a soft limit: the plugin is required to gracefully accept all values in
the range of a port's data type.

"""^^lv2:Markdown .

lv2:optionalFeature
    lv2:documentation """

To support this feature, the host MUST pass its URI and any additional data to
the plugin in LV2_Descriptor::instantiate().

The plugin MUST NOT fail to instantiate if an optional feature is not supported
by the host.

"""^^lv2:Markdown .

lv2:requiredFeature
    lv2:documentation """

To support this feature, the host MUST pass its URI and any additional data to
the plugin in LV2_Descriptor::instantiate().

The host MUST check this property before attempting to instantiate a plugin,
and not attempt to instantiate plugins which require features it does not
support.  The plugin MUST fail to instantiate if a required feature is not
supported by the host.  Note that these rules are intentionally redundant for
resilience: neither host nor plugin should assume that the other does not
violate them.

"""^^lv2:Markdown .

lv2:ExtensionData
    lv2:documentation """

This is additional data that a plugin may return from
LV2_Descriptor::extension_data().  This is generally used to add APIs to extend
that defined by LV2_Descriptor.

"""^^lv2:Markdown .

lv2:extensionData
    lv2:documentation """

If a plugin has a value for this property, it must be a URI that defines the
extension data.  The plugin should return the appropriate data when
LV2_Descriptor::extension_data() is called with that URI as a parameter.

"""^^lv2:Markdown .

lv2:isLive
    lv2:documentation """

This feature is for plugins that have time-sensitive internals, for example
communicating in real time over a socket.  It indicates to the host that its
input and output must not be cached or subject to significant latency, and that
calls to LV2_Descriptor::run() should be made at a rate that roughly
corresponds to wall clock time (according to the `sample_count` parameter).

Note that this feature is not related to <q>hard real-time</q> execution
requirements (see lv2:hardRTCapable).

"""^^lv2:Markdown .

lv2:inPlaceBroken
    lv2:documentation """

This feature indicates that the plugin may not work correctly if the host
elects to use the same data location for both input and output.  Plugins that
will fail to work correctly if ANY input port is connected to the same location
as ANY output port MUST require this feature.  Doing so should be avoided
whenever possible since it prevents hosts from running the plugin on data
<q>in-place</q>.

"""^^lv2:Markdown .

lv2:hardRTCapable
    lv2:documentation """

This feature indicates that the plugin is capable of running in a <q>hard
real-time</q> environment.  This should be the case for most audio processors,
so most plugins are expected to have this feature.

To support this feature, plugins MUST adhere to the following in all of their
audio class functions (LV2_Descriptor::run() and
LV2_Descriptor::connect_port()):

  * There is no use of `malloc()`, `free()` or any other heap memory management
    functions.

  * There is no use of any library functions which do not adhere to these
    rules.  The plugin may assume that the standard C math library functions
    are safe.

  * There is no access to files, devices, pipes, sockets, system calls, or any
    other mechanism that might result in the process or thread blocking.

  * The maximum amount of time for a `run()` call is bounded by some expression
    of the form `A + B * sample_count`, where `A` and `B` are platform specific
    constants.  Note that this bound does not depend on input signals or plugin
    state.

"""^^lv2:Markdown .

lv2:portProperty
    lv2:documentation """

States that a port has a particular lv2:PortProperty.  This may be ignored
without catastrophic effects, though it may be useful, for example to provide a
sensible user interface for the port.

"""^^lv2:Markdown .

lv2:connectionOptional
    lv2:documentation """

This property means that the port does not have to be connected to valid data
by the host.  To leave a port <q>unconnected</q>, the host MUST explicitly
connect the port to `NULL`.

"""^^lv2:Markdown .

lv2:reportsLatency
    lv2:documentation """

This property indicates that the port is used to express the processing latency
incurred by the plugin, expressed in samples.  The latency may be affected by
the current sample rate, plugin settings, or other factors, and may be changed
by the plugin at any time.  Where the latency is frequency dependent the plugin
may choose any appropriate value.  If a plugin introduces latency it MUST
provide EXACTLY ONE port with this property set.  In <q>fuzzy</q> cases the
value should be the most reasonable one based on user expectation of
input/output alignment.  For example, musical delay plugins should not report
their delay as latency, since it is an intentional effect that the host should
not compensate for.

This property is deprecated, use a lv2:designation of lv2:latency instead,
following the same rules as above:

    :::turtle
    <http://example.org/plugin>
        lv2:port [
            a lv2:OutputPort , lv2:ControlPort ;
            lv2:designation lv2:latency ;
            lv2:symbol "latency" ;
        ]

"""^^lv2:Markdown .

lv2:toggled
    lv2:documentation """

Indicates that the data item should be considered a boolean toggle.  Data less
than or equal to zero should be considered <q>off</q> or <q>false</q>, and data
above zero should be considered <q>on</q> or <q>true</q>.

"""^^lv2:Markdown .

lv2:sampleRate
    lv2:documentation """

Indicates that any specified bounds should be interpreted as multiples of the
sample rate.  For example, a frequency range from 0 Hz to the Nyquist frequency
(half the sample rate) can be specified by using this property with lv2:minimum
0.0 and lv2:maximum 0.5.  Hosts that support bounds at all MUST support this
property.

"""^^lv2:Markdown .

lv2:integer
    lv2:documentation """

Indicates that all the reasonable values for a port)lv2ttl" R"lv2ttl( are integers.  For such
ports, a user interface should provide a stepped control that only allows
choosing integer values.

Note that this is only a hint, and that the plugin MUST operate reasonably even
if such a port has a non-integer value.

"""^^lv2:Markdown .

lv2:enumeration
    lv2:documentation """

Indicates that all the rasonable values for a port are defined by
lv2:scalePoint properties.  For such ports, a user interface should provide a selector that allows the user to choose any of the scale point values by name.  It is recommended to show the value as well if possible.

Note that this is only a hint, and that the plugin MUST operate reasonably even
if such a port has a value that does not correspond to a scale point.

"""^^lv2:Markdown .

lv2:isSideChain
    lv2:documentation """

Indicates that a port is a <q>sidechain</q>, which affects the output somehow
but should not be considered a part of the main signal chain.  Sidechain ports
SHOULD be lv2:connectionOptional, and may be ignored by hosts.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"lv2core.ttl",
R"lv2ttl(@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/lv2core>
    a owl:Ontology ;
    rdfs:label "LV2" ;
    rdfs:comment "An extensible open standard for audio plugins." ;
    rdfs:seeAlso <lv2.h> ,
        <lv2_util.h> ,
        <lv2core.meta.ttl> .

lv2:Specification
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf doap:Project ;
    rdfs:label "Specification" ;
    rdfs:comment "An LV2 specifiation." .

lv2:Markdown
    a rdfs:Datatype ;
    owl:onDatatype xsd:string ;
    rdfs:label "Markdown" ;
    rdfs:comment "A string in Markdown syntax." .

lv2:documentation
    a rdf:Property ,
        owl:AnnotationProperty ;
    rdfs:range rdfs:Literal ;
    rdfs:label "documentation" ;
    rdfs:comment "Extended documentation." ;
    rdfs:seeAlso <http://www.w3.org/TR/xhtml-basic/> .

lv2:PluginBase
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Plugin Base" ;
    rdfs:comment "Base class for a plugin-like resource." .

lv2:Plugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:PluginBase ;
    rdfs:label "Plugin" ;
    rdfs:comment "An LV2 plugin." ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty doap:name ;
        owl:someValuesFrom rdf:PlainLiteral ;
        rdfs:comment "A plugin MUST have at least one untranslated doap:name."
    ] , [
        a owl:Restriction ;
        owl:onProperty lv2:port ;
        owl:allValuesFrom lv2:Port ;
        rdfs:comment "All ports on a plugin MUST be fully specified lv2:Port instances."
    ] .

lv2:PortBase
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Port Base" ;
    rdfs:comment "Base class for a port-like resource." ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty lv2:symbol ;
        owl:cardinality 1 ;
        rdfs:comment "A port MUST have exactly one lv2:symbol."
    ] .

lv2:Port
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Port" ;
    rdfs:comment "An LV2 plugin port." ;
    rdfs:subClassOf lv2:PortBase ,
    [
        a owl:Restriction ;
        owl:onProperty lv2:name ;
        owl:minCardinality 1 ;
        rdfs:comment "A port MUST have at least one lv2:name."
    ] .

lv2:InputPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Input Port" ;
    rdfs:comment "A port connected to constant data which is read during `run()`." .

lv2:OutputPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Output Port" ;
    rdfs:comment "A port connected to data which is written during `run()`." .

lv2:ControlPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Control Port" ;
    rdfs:comment "A port connected to a single `float`." .

lv2:AudioPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Audio Port" ;
    rdfs:comment "A port connected to an array of float audio samples." .

lv2:CVPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "CV Port" ;
    rdfs:comment "A port connected to an array of float control values." .

lv2:port
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain lv2:PluginBase ;
    rdfs:range lv2:PortBase ;
    rdfs:label "port" ;
    rdfs:comment "A port (input or output) on this plugin." .

lv2:project
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range doap:Project ;
    rdfs:label "project" ;
    rdfs:comment "The project this is a part of." .

lv2:prototype
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "prototype" ;
    rdfs:comment "The prototype to inherit properties from." .

lv2:minorVersion
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "minor version" ;
    rdfs:comment "The minor version of this resource." .

lv2:microVersion
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "micro version" ;
    rdfs:comment "The micro version of this resource." .

lv2:binary
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range owl:Thing ;
    rdfs:label "binary" ;
    rdfs:comment "The binary of this resource." .

lv2:appliesTo
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range lv2:Plugin ;
    rdfs:label "applies to" ;
    rdfs:comment "The plugin this resource is related to." .

lv2:index
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:range xsd:unsignedInt ;
    rdfs:label "index" ;
    rdfs:comment "A non-negative zero-based 32-bit index." .

lv2:Symbol
    a rdfs:Datatype ;
    owl:onDatatype xsd:string ;
    owl:withRestrictions (
        [
            xsd:pattern "[_a-zA-Z][_a-zA-Z0-9]*"
        ]
    ) ;
    rdfs:label "Symbol" ;
    rdfs:comment "A short restricted name used as a strong identifier." .

lv2:symbol
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "symbol" ;
    rdfs:range lv2:Symbol ,
        rdf:PlainLiteral ;
    rdfs:comment "The symbol that identifies this resource in the context of its parent." .

lv2:name
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "name" ;
    rdfs:range xsd:string ;
    rdfs:comment "A display name for labeling in a user interface." .

lv2:shortName
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "short name" ;
    rdfs:range xsd:string ;
    rdfs:comment "A short display name for labeling in a user interface." .

lv2:Designation
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf rdf:Property ;
    rdfs:label "Designation" ;
    rdfs:comment "A designation which defines the meaning of some data." .

lv2:Channel
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Designation ;
    rdfs:label "Channel" ;
    rdfs:comment "An individual channel, such as left or right." .

lv2:Parameter
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Designation ,
        rdf:Property ;
    rdfs:label "Parameter" ;
    rdfs:comment "A property that is a plugin parameter." .

lv2:designation
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:range rdf:Property ;
    rdfs:label "designation" ;
    rdfs:comment "The designation that defines the meaning of this input or output." .

lv2:latency
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "latency" ;
    rdfs:comment "The latency introduced, in frames." .

lv2:freeWheeling
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "free-wheeling" ;
    rdfs:range xsd:boolean ;
    rdfs:comment "Whether processing is currently free-wheeling." .

lv2:enabled
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "enabled" ;
    rdfs:range xsd:int ;
    rdfs:comment "Whether processing is currently enabled (not bypassed)." .

lv2:control
    a lv2:Channel ;
    rdfs:label "control" ;
    rdfs:comment "The primary control channel." .

lv2:Point
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Point" ;
    rdfs:comment "An interesting point in a value range." .

lv2:ScalePoint
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Point ;
    rdfs:label "Scale Point" ;
    rdfs:comment "A single `float` Point for control inputs." .

lv2:scalePoint
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range lv2:ScalePoint ;
    rdfs:label "scale point" ;
    rdfs:comment "A scale point of a port or parameter." .

lv2:default
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "default" ;
    rdfs:comment "The default value for this control." .

lv2:minimum
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "minimum" ;
    rdfs:comment "The minimum value for this control." .

lv2:maximum
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "maximum" ;
    rdfs:comment "The maximum value for this control." .

lv2:Feature
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Feature" ;
    rdfs:comment "An additional feature which may be used or required." .

lv2:optionalFeature
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range lv2:Feature ;
    rdfs:label "optional feature" ;
    rdfs:comment "An optional feature that is supported if available." .

lv2:requiredFeature
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range lv2:Feature ;
    rdfs:label "required feature" ;
    rdfs:comment "A requir)lv2ttl" R"lv2ttl(ed feature that must be available to run." .

lv2:ExtensionData
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Extension Data" ;
    rdfs:comment "Additional data defined by an extension." .

lv2:extensionData
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range lv2:ExtensionData ;
    rdfs:label "extension data" ;
    rdfs:comment "Extension data provided by a plugin or other binary." .

lv2:isLive
    a lv2:Feature ;
    rdfs:label "is live" ;
    rdfs:comment "Plugin has a real-time dependency." .

lv2:inPlaceBroken
    a lv2:Feature ;
    rdfs:label "in-place broken" ;
    rdfs:comment "Plugin requires separate locations for input and output." .

lv2:hardRTCapable
    a lv2:Feature ;
    rdfs:label "hard real-time capable" ;
    rdfs:comment "Plugin is capable of running in a hard real-time environment." .

lv2:PortProperty
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Port Property" ;
    rdfs:comment "A particular property that a port has." .

lv2:portProperty
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain lv2:Port ;
    rdfs:range lv2:PortProperty ;
    rdfs:label "port property" ;
    rdfs:comment "A property of this port hosts may find useful." .

lv2:connectionOptional
    a lv2:PortProperty ;
    rdfs:label "connection optional" ;
    rdfs:comment "The property that this port may be connected to NULL." .

lv2:reportsLatency
    a lv2:PortProperty ;
    owl:deprecated "true"^^xsd:boolean ;
    rdfs:label "reports latency" ;
    rdfs:comment "Control port value is the plugin latency in frames." .

lv2:toggled
    a lv2:PortProperty ;
    rdfs:label "toggled" ;
    rdfs:comment "Control port value is considered a boolean toggle." .

lv2:sampleRate
    a lv2:PortProperty ;
    rdfs:label "sample rate" ;
    rdfs:comment "Control port bounds are interpreted as multiples of the sample rate." .

lv2:integer
    a lv2:PortProperty ;
    rdfs:label "integer" ;
    rdfs:comment "Control port values are treated as integers." .

lv2:enumeration
    a lv2:PortProperty ;
    rdfs:label "enumeration" ;
    rdfs:comment "Control port scale points represent all useful values." .

lv2:isSideChain
    a lv2:PortProperty ;
    rdfs:label "is side-chain" ;
    rdfs:comment "Signal for port should not be considered a main input or output." .

lv2:GeneratorPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Generator Plugin" ;
    rdfs:comment "A plugin that generates new sound internally." .

lv2:InstrumentPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:GeneratorPlugin ;
    rdfs:label "Instrument Plugin" ;
    rdfs:comment "A plugin intended to be played as a musical instrument." .

lv2:OscillatorPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:GeneratorPlugin ;
    rdfs:label "Oscillator Plugin" ;
    rdfs:comment "A plugin that generates output with an oscillator." .

lv2:UtilityPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Utility Plugin" ;
    rdfs:comment "A utility plugin that is not a typical audio effect or generator." .

lv2:ConverterPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:UtilityPlugin ;
    rdfs:label "Converter Plugin" ;
    rdfs:comment "A plugin that converts its input into a different form." .

lv2:AnalyserPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:UtilityPlugin ;
    rdfs:label "Analyser Plugin" ;
    rdfs:comment "A plugin that analyses its input and emits some useful information." .

lv2:MixerPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:UtilityPlugin ;
    rdfs:label "Mixer Plugin" ;
    rdfs:comment "A plugin that mixes some number of inputs into some number of outputs." .

lv2:SimulatorPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Simulator Plugin" ;
    rdfs:comment "A plugin that aims to emulate some environmental effect or musical equipment." .

lv2:DelayPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Delay Plugin" ;
    rdfs:comment "An effect that intentionally delays its input as an effect." .

lv2:ModulatorPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Modulator Plugin" ;
    rdfs:comment "An effect that modulats its input as an effect." .

lv2:ReverbPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ,
        lv2:SimulatorPlugin ,
        lv2:DelayPlugin ;
    rdfs:label "Reverb Plugin" ;
    rdfs:comment "An effect that adds reverberation to its input." .

lv2:PhaserPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:ModulatorPlugin ;
    rdfs:label "Phaser Plugin" ;
    rdfs:comment "An effect that periodically sweeps a filter over its input." .

lv2:FlangerPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:ModulatorPlugin ;
    rdfs:label "Flanger Plugin" ;
    rdfs:comment "An effect that mixes slightly delayed copies of its input." .

lv2:ChorusPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:ModulatorPlugin ;
    rdfs:label "Chorus Plugin" ;
    rdfs:comment "An effect that mixes significantly delayed copies of its input." .

lv2:FilterPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Filter Plugin" ;
    rdfs:comment "An effect that manipulates the frequency spectrum of its input." .

lv2:LowpassPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:FilterPlugin ;
    rdfs:label "Lowpass Filter Plugin" ;
    rdfs:comment "A filter that attenuates frequencies above some cutoff." .

lv2:BandpassPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:FilterPlugin ;
    rdfs:label "Bandpass Filter Plugin" ;
    rdfs:comment "A filter that attenuates frequencies outside of some band." .

lv2:HighpassPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:FilterPlugin ;
    rdfs:label "Highpass Filter Plugin" ;
    rdfs:comment "A filter that attenuates frequencies below some cutoff." .

lv2:CombPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:FilterPlugin ;
    rdfs:label "Comb FilterPlugin" ;
    rdfs:comment "A filter that adds a delayed version of its input to itself." .

lv2:AllpassPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:FilterPlugin ;
    rdfs:label "Allpass Plugin" ;
    rdfs:comment "A filter that changes the phase relationship between frequency components." .

lv2:EQPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:FilterPlugin ;
    rdfs:label "Equaliser Plugin" ;
    rdfs:comment "A plugin that adjusts the balance between frequency components." .

lv2:ParaEQPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:EQPlugin ;
    rdfs:label "Parametric EQ Plugin" ;
    rdfs:comment "A plugin that adjusts the balance between configurable frequency components." .

lv2:MultiEQPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:EQPlugin ;
    rdfs:label "Multiband EQ Plugin" ;
    rdfs:comment "A plugin that adjusts the balance between a fixed set of frequency components." .

lv2:SpatialPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Spatial Plugin" ;
    rdfs:comment "A plugin that manipulates the position of audio in space." .

lv2:SpectralPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Spectral Plugin" ;
    rdfs:comment "A plugin that alters the spectral properties of audio." .

lv2:PitchPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:SpectralPlugin ;
    rdfs:label "Pitch Shifter Plugin" ;
    rdfs:comment "A plugin that shifts the pitch of its input." .

lv2:AmplifierPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DynamicsPlugin ;
    rdfs:label "Amplifier Plugin" ;
    rdfs:comment "A plugin that primarily changes the volume of its input." .

lv2:EnvelopePlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DynamicsPlugin ;
    rdfs:label "Envelope Plugin" ;
    rdfs:comment "A plugin that applies an envelope to its input." .

lv2:DistortionPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Distortion Plugin" ;
    rdfs:comment "A plugin that adds distortion to its input." .

lv2:WaveshaperPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DistortionPlugin ;
    rdfs:label "Waveshaper Plugin" ;
    rdfs:comment "An effect that alters t)lv2ttl" R"lv2ttl(he shape of input waveforms." .

lv2:DynamicsPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "Dynamics Plugin" ;
    rdfs:comment "A plugin that alters the envelope or dynamic range of its input." .

lv2:CompressorPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DynamicsPlugin ;
    rdfs:label "Compressor Plugin" ;
    rdfs:comment "A plugin that reduces the dynamic range of its input." .

lv2:ExpanderPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DynamicsPlugin ;
    rdfs:label "Expander Plugin" ;
    rdfs:comment "A plugin that expands the dynamic range of its input." .

lv2:LimiterPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DynamicsPlugin ;
    rdfs:label "Limiter Plugin" ;
    rdfs:comment "A plugin that limits its input to some maximum level." .

lv2:GatePlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:DynamicsPlugin ;
    rdfs:label "Gate Plugin" ;
    rdfs:comment "A plugin that attenuates signals below some threshold." .

lv2:FunctionPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:UtilityPlugin ;
    rdfs:label "Function Plugin" ;
    rdfs:comment "A plugin whose output is a mathmatical function of its input." .

lv2:ConstantPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:GeneratorPlugin ;
    rdfs:label "Constant Plugin" ;
    rdfs:comment "A plugin that emits constant values." .

lv2:MIDIPlugin
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Plugin ;
    rdfs:label "MIDI Plugin" ;
    rdfs:comment "A plugin that primarily processes MIDI messages." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"port-props",
{
juce::lv2::BundleResource
{
"port-props.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix pprops: <http://lv2plug.in/ns/ext/port-props#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/port-props>
    a owl:Ontology ;
    rdfs:label "LV2 Port Properties" ;
    rdfs:comment "Various properties for LV2 plugin ports." ;
    rdfs:seeAlso <port-props.meta.ttl> .

pprops:trigger
    a lv2:PortProperty ;
    rdfs:label "trigger" ;
    rdfs:comment "Port is a momentary trigger." .

pprops:supportsStrictBounds
    a lv2:Feature ;
    rdfs:label "supports strict bounds" ;
    rdfs:comment "A feature indicating plugin support for strict port bounds." .

pprops:hasStrictBounds
    a lv2:PortProperty ;
    rdfs:label "has strict bounds" ;
    rdfs:comment "Port has strict bounds which are not internally clamped." .

pprops:expensive
    a lv2:PortProperty ;
    rdfs:label "changes are expensive" ;
    rdfs:comment "Input port is expensive to change." .

pprops:causesArtifacts
    a lv2:PortProperty ;
    rdfs:label "changes cause artifacts" ;
    rdfs:comment "Input port causes audible artifacts when changed." .

pprops:continuousCV
    a lv2:PortProperty ;
    rdfs:label "smooth modulation signal" ;
    rdfs:comment "Port carries a smooth modulation signal." .

pprops:discreteCV
    a lv2:PortProperty ;
    rdfs:label "discrete modulation signal" ;
    rdfs:comment "Port carries a discrete modulation signal." .

pprops:logarithmic
    a lv2:PortProperty ;
    rdfs:label "logarithmic" ;
    rdfs:comment "Port value is logarithmic." .

pprops:notAutomatic
    a lv2:PortProperty ;
    rdfs:label "not automatic" ;
    rdfs:comment "Port that is not intended to be fed with a modulation signal." .

pprops:notOnGUI
    a lv2:PortProperty ;
    rdfs:label "not on GUI" ;
    rdfs:comment "Port that should not be displayed on a GUI." .

pprops:displayPriority
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain lv2:Port ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "display priority" ;
    rdfs:comment "A priority ranking this port in importance to its plugin." .

pprops:rangeSteps
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain lv2:Port ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "range steps" ;
    rdfs:comment "The number of even steps the range should be divided into." .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/port-props>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 2 ;
    rdfs:seeAlso <port-props.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"port-props.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix pprops: <http://lv2plug.in/ns/ext/port-props#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/port-props>
    a doap:Project ;
    doap:name "LV2 Port Properties" ;
    doap:created "2009-01-01" ;
    doap:shortdesc "Various properties for LV2 plugin ports." ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:developer <http://lv2plug.in/ns/meta#kfoltman> ;
    doap:release [
        doap:revision "1.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This vocabulary defines various properties for plugin ports, which can be used
to better describe how a plugin can be controlled.  Using this metadata, hosts
can build better UIs for plugins, and provide more advanced automatic
functionality.

"""^^lv2:Markdown .

pprops:trigger
    lv2:documentation """

Indicates that the data item corresponds to a momentary event that has been
detected (control output ports) or is to be triggered (control input ports).
For input ports, the port needs to be reset to lv2:default value after run()
function of the plugin has returned.  If the control port is assigned a GUI
widget by the host, the widget should be of auto-off (momentary, one-shot) type
- for example, a push button if the port is also declared as lv2:toggled, or a
series of push button or auto-clear input box with a "Send" button if the port
is also lv2:integer.

"""^^lv2:Markdown .

pprops:supportsStrictBounds
    lv2:documentation """

Indicates use of host support for pprops:hasStrictBounds port property.  A
plugin that specifies it as optional feature can omit value clamping for
hasStrictBounds ports, if the feature is supported by the host.  When specified
as required feature, it indicates that the plugin does not do any clamping for
input ports that have a pprops:hasStrictBounds property.

"""^^lv2:Markdown .

pprops:hasStrictBounds
    lv2:documentation """

For hosts that support pprops:supportsStrictBounds, this indicates that the
value of the port should never exceed the port's minimum and maximum control
points.  For input ports, it moves the responsibility for limiting the range of
values to host, if it supports pprops:supportsStrictBounds.  For output ports,
it indicates that values within specified range are to be expected, and
breaking that should be considered by the host as error in plugin
implementation.

"""^^lv2:Markdown .

pprops:expensive
    lv2:documentation """

Input ports only.  Indicates that any changes to the port value may trigger
expensive background calculation (for example, regeneration of lookup tables in
a background thread).  Any value changes may have not have immediate effect, or
may cause silence or diminished-quality version of the output until background
processing is finished.  Ports having this property are typically not well
suited for connection to outputs of other plugins, and should not be offered as
connection targets or for automation by default.

"""^^lv2:Markdown .

pprops:causesArtifacts
    lv2:documentation """

Input ports only.  Indicates that any changes to the port value may produce
slight artifacts to produced audio signals (zipper noise and other results of
signal discontinuities).  Connecting ports of this type to continuous signals
is not recommended, and when presenting a list of automation targets, those
ports may be marked as artifact-producing.

"""^^lv2:Markdown .

pprops:continuousCV
    lv2:documentation """

Indicates that the port carries a "smooth" modulation signal.  Control input
ports of this type are well-suited for being connected to sources of smooth
signals (knobs with smoothing, modulation rate oscillators, output ports with
continuousCV type, etc.).  Typically, the plugin with ports which have this
property will implement appropriate smoothing to avoid audio artifacts.  For
output ports, this property suggests the value of the port is likely to change
frequently, and describes a smooth signal (so successive values may be
considered points along a curve).

"""^^lv2:Markdown .

pprops:discreteCV
    lv2:documentation """

Indicates that the port carries a "discrete" modulation signal.  Input ports of
this type are well-suited for being connected to sources of discrete signals
(switches, buttons, classifiers, event detectors, etc.).  May be combined with
pprops:trigger property.  For output ports, this property suggests the value of
the port describe discrete values that should be interpreted as steps (and not
points along a curve).

"""^^lv2:Markdown .

pprops:logarithmic
    lv2:documentation """

Indicates that port value behaviour within specified range (bounds) is a value
using logarithmic scale.  The lower and upper bounds must be specified, and
must be of the same sign.

"""^^lv2:Markdown .

pprops:notAutomatic
    lv2:documentation """

Indicates that the port is not primarily intended to be fed with modulation
signals from external sources (other plugins, etc.).  It is merely a UI hint
and hosts may allow the user to override it.

"""^^lv2:Markdown .

pprops:notOnGUI
    lv2:documentation """

Indicates that the port is not primarily intended to be represented by a
separate control in the user interface window (or any similar mechanism used
for direct, immediate control of control ports).  It is merely a UI hint and
hosts may allow the user to override it.

"""^^lv2:Markdown .

pprops:displayPriority
    lv2:documentation """

Indicates how important a port is to controlling the plugin.  If a host can
only display some ports of a plugin, it should prefer ports with a higher
display priority.  Priorities do not need to be unique, and are only meaningful
when compared to each other.

"""^^lv2:Markdown .

pprops:rangeSteps
    lv2:documentation """

This value indicates into how many evenly-divided points the (control) port
range should be divided for step-wise control.  This may be used for changing
the value with step-based controllers like arrow keys, mouse wheel, rotary
encoders, and so on.

Note that when used with a pprops:logarithmic port, the steps are logarithmic
too, and port value can be calculated as:

    :::c
    value = lower * pow(upper / lower, step / (steps - 1))

and the step from value is:

    :::c
    step = (steps - 1) * log(value / lower) / log(upper / lower)

where:

  * `value` is the port value.

  * `step` is the step number (0..steps).

  * `steps` is the number of steps (= value of :rangeSteps property).

  * `lower` and <code>upper</code> are the bounds.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"midi",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/midi>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 10 ;
    rdfs:seeAlso <midi.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"midi.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix midi: <http://lv2plug.in/ns/ext/midi#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/midi>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 MIDI" ;
    doap:shortdesc "A normalised definition of raw MIDI." ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:created "2006-00-00" ;
    doap:developer <http://lv2plug.in/ns/meta#larsl> ,
        <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.10" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix incorrect range of midi:chunk."
            ]
        ]
    ] , [
        doap:revision "1.8" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ] , [
                rdfs:label "Add midi:binding and midi:channel predicates."
            ] , [
                rdfs:label "Add midi:HexByte datatype for status bytes and masks."
            ] , [
                rdfs:label "Remove non-standard midi:Tick message type."
            ] , [
                rdfs:label "Add C definitions for message types and standard controllers."
            ] , [
                rdfs:label "Fix definition of SystemExclusive status byte."
            ]
        ]
    ] , [
        doap:revision "1.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add class definitions for various message types."
            ] , [
                rdfs:label "Document how to serialise a MidiEvent to a string."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-midi-1.4.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2011-05-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-midi-1.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system for installation."
            ] , [
                rdfs:label "Switch to ISC license."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2010-10-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-midi-1.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This specification defines a data type for a MIDI message, midi:MidiEvent,
which is normalised for fast and convenient real-time processing.  MIDI is the
<q>Musical Instrument Digital Interface</q>, a ubiquitous binary standard for
controlling digital music devices.

For plugins that process MIDI (or other situations where MIDI is sent via a
generic transport) the main type defined here, midi:MidiEvent, can be mapped to
an integer and used as the type of an LV2 [Atom](atom.html#Atom) or
[Event](event.html#Event).

This specification also defines a complete vocabulary for the MIDI standard,
except for standard controller numbers.  These descriptions are detailed enough
to express any MIDI message as properties.

"""^^lv2:Markdown .

midi:MidiEvent
    lv2:documentation """

A single raw MIDI message (a sequence of bytes).

This is equivalent to a standard MIDI messages, except with the following
restrictions to simplify handling:

  * Running status is not allowed, every message must have its own status byte.

  * Note On messages with velocity 0 are not allowed.  These messages are
    equivalent to Note Off in standard MIDI streams, but here only proper Note
    Off messages are allowed.

  * "Realtime messages" (status bytes 0xF8 to 0xFF) are allowed, but may not
     occur inside other messages like they can in standard MIDI streams.

  * All messages are complete valid MIDI messages.  This means, for example,
    that only the first byte in each event (the status byte) may have the
    eighth bit set, that Note On and Note Off events are always 3 bytes long,
    etc.

Where messages are communicated, the writer is responsible for writing valid
messages, and the reader may assume that all events are valid.

If a midi:MidiEvent is serialised to a string, the format should be
xsd:hexBinary, for example:

    :::turtle
    [] eg:someEvent "901A01"^^midi:MidiEvent .

"""^^lv2:Markdown .

midi:statusMask
    lv2:documentation """

This is a status byte with the lower nibble set to zero.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"midi.ttl",
R"lv2ttl(@prefix atom: <http://lv2plug.in/ns/ext/atom#> .
@prefix ev: <http://lv2plug.in/ns/ext/event#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix midi: <http://lv2plug.in/ns/ext/midi#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/midi>
    a owl:Ontology ;
    rdfs:label "LV2 MIDI" ;
    rdfs:comment "A normalised definition of raw MIDI." ;
    rdfs:seeAlso <midi.h> ,
        <midi.meta.ttl> .

midi:ActiveSense
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemRealtime ;
    rdfs:label "Active Sense" ;
    rdfs:comment "MIDI active sense message." ;
    midi:status "FE"^^xsd:hexBinary .

midi:Aftertouch
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Aftertouch" ;
    rdfs:comment "MIDI aftertouch message." ;
    midi:statusMask "A0"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ;
        midi:property midi:noteNumber
    ] , [
        midi:byteNumber 1 ;
        midi:property midi:pressure
    ] .

midi:Bender
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Bender" ;
    rdfs:comment "MIDI bender message." ;
    midi:statusMask "E0"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ,
            1 ;
        midi:property midi:benderValue
    ] .

midi:ChannelPressure
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Channel Pressure" ;
    rdfs:comment "MIDI channel pressure message." ;
    midi:statusMask "D0"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ;
        midi:property midi:pressure
    ] .

midi:Chunk
    a rdfs:Class ;
    rdfs:label "Chunk" ;
    rdfs:comment "A sequence of contiguous bytes in a MIDI message." .

midi:Clock
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemRealtime ;
    rdfs:label "Clock" ;
    rdfs:comment "MIDI clock message." ;
    midi:status "F8"^^xsd:hexBinary .

midi:Continue
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemRealtime ;
    rdfs:label "Continue" ;
    rdfs:comment "MIDI continue message." ;
    midi:status "FB"^^xsd:hexBinary .

midi:Controller
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Controller" ;
    rdfs:comment "MIDI controller change message." ;
    midi:statusMask "B0"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ;
        midi:property midi:controllerNumber
    ] , [
        midi:byteNumber 1 ;
        midi:property midi:controllerValue
    ] .

midi:HexByte
    a rdfs:Datatype ;
    owl:onDatatype xsd:hexBinary ;
    owl:withRestrictions (
        [
            xsd:maxInclusive "FF"
        ]
    ) ;
    rdfs:label "Hex Byte" ;
    rdfs:comment "A hexadecimal byte, which has a value <= FF." .

midi:MidiEvent
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf ev:Event ,
        atom:Atom ;
    owl:onDatatype xsd:hexBinary ;
    rdfs:label "MIDI Message" ;
    rdfs:comment "A single raw MIDI message." .

midi:NoteOff
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Note Off" ;
    rdfs:comment "MIDI note off message." ;
    midi:statusMask "80"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ;
        midi:property midi:noteNumber
    ] , [
        midi:byteNumber 1 ;
        midi:property midi:velocity
    ] .

midi:NoteOn
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Note On" ;
    rdfs:comment "MIDI note on message." ;
    midi:statusMask "90"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ;
        midi:property midi:noteNumber
    ] , [
        midi:byteNumber 1 ;
        midi:property midi:velocity
    ] .

midi:ProgramChange
    a rdfs:Class ;
    rdfs:subClassOf midi:VoiceMessage ;
    rdfs:label "Program Change" ;
    rdfs:comment "MIDI program change message." ;
    midi:statusMask "C0"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ;
        midi:property midi:programNumber
    ] .

midi:QuarterFrame
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemCommon ;
    rdfs:label "Quarter Frame" ;
    rdfs:comment "MIDI quarter frame message." ;
    midi:status "F1"^^xsd:hexBinary .

midi:Reset
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemRealtime ;
    rdfs:label "Reset" ;
    rdfs:comment "MIDI reset message." ;
    midi:status "FF"^^xsd:hexBinary .

midi:SongPosition
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemCommon ;
    rdfs:label "Song Position" ;
    rdfs:comment "MIDI song position pointer message." ;
    midi:status "F2"^^xsd:hexBinary ;
    midi:chunk [
        midi:byteNumber 0 ,
            1 ;
        midi:property midi:songPosition
    ] .

midi:SongSelect
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemCommon ;
    rdfs:label "Song Select" ;
    rdfs:comment "MIDI song select message." ;
    midi:status "F3"^^xsd:hexBinary .

midi:Start
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemRealtime ;
    rdfs:label "Start" ;
    rdfs:comment "MIDI start message." ;
    midi:status "FA"^^xsd:hexBinary .

midi:Stop
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemRealtime ;
    rdfs:label "Stop" ;
    rdfs:comment "MIDI stop message." ;
    midi:status "FC"^^xsd:hexBinary .

midi:SystemCommon
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemMessage ;
    rdfs:label "System Common" ;
    rdfs:comment "MIDI system common message." .

midi:SystemExclusive
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemMessage ;
    rdfs:label "System Exclusive" ;
    rdfs:comment "MIDI system exclusive message." ;
    midi:status "F0"^^xsd:hexBinary .

midi:SystemMessage
    a rdfs:Class ;
    rdfs:subClassOf midi:MidiEvent ;
    rdfs:label "System Message" ;
    rdfs:comment "MIDI system message." ;
    midi:statusMask "F0"^^xsd:hexBinary .

midi:SystemRealtime
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemMessage ;
    rdfs:label "System Realtime" ;
    rdfs:comment "MIDI system realtime message." .

midi:TuneRequest
    a rdfs:Class ;
    rdfs:subClassOf midi:SystemCommon ;
    rdfs:label "Tune Request" ;
    rdfs:comment "MIDI tune request message." ;
    midi:status "F6"^^xsd:hexBinary .

midi:VoiceMessage
    a rdfs:Class ;
    rdfs:subClassOf midi:MidiEvent ;
    rdfs:label "Voice Message" ;
    rdfs:comment "MIDI voice message." ;
    midi:statusMask "F0"^^xsd:hexBinary .

midi:benderValue
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "bender value" ;
    rdfs:range xsd:short ;
    rdfs:comment "MIDI pitch bender message (-8192 to 8192)." .

midi:binding
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range midi:MidiEvent ;
    rdfs:label "binding" ;
    rdfs:comment "The MIDI event to bind a parameter to." .

midi:byteNumber
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "byte number" ;
    rdfs:domain midi:Chunk ;
    rdfs:range xsd:unsignedByte ;
    rdfs:comment "The 0-based index of a byte which is part of this chunk." .

midi:channel
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "MIDI channel" ;
    rdfs:range xsd:unsignedByte ;
    rdfs:comment "The channel number of a MIDI message." .

midi:chunk
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range midi:Chunk ;
    rdfs:label "MIDI chunk" ;
    rdfs:comment "A chunk of a MIDI message." .

midi:controllerNumber
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "MIDI controller number" ;
    rdfs:range xsd:byte ;
    rdfs:comment "The numeric ID of a controller (0 to 127)." .

midi:controllerValue
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "MIDI controller value" ;
    rdfs:range xsd:byte ;
    rdfs:comment "The value of a controller (0 to 127)." .

midi:noteNumber
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "note number" ;
    rdfs:range xsd:byte ;
    rdfs:comment "The numeric ID of a note (0 to 127)." .

midi:pressure
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "key pressure" ;
    rdfs:range xsd:byte ;
    rdfs:comment "Key pressure (0 to 127)." .

midi:programNumber
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "program number" ;
    rdfs:range xsd:byte ;
    rdfs:comment "The numeric ID of a program (0 to 127)." .

midi:property
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:label "property" ;
    rdfs:domain midi:Chunk ;
    rdfs:range rdf:Property ;
    rdfs:comment "The property this chunk represents." .

midi:songNumber
    a rdf:Property ,
        owl:)lv2ttl" R"lv2ttl(DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "song number" ;
    rdfs:range xsd:byte ;
    rdfs:comment "The numeric ID of a song (0 to 127)." .

midi:songPosition
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "song position" ;
    rdfs:range xsd:short ;
    rdfs:comment "Song position in MIDI beats (16th notes) (-8192 to 8192)." .

midi:status
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "status byte" ;
    rdfs:range midi:HexByte ;
    rdfs:comment "The exact status byte for a message of this type." .

midi:statusMask
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "status mask" ;
    rdfs:range midi:HexByte ;
    rdfs:comment "The status byte for a message of this type on channel 1." .

midi:velocity
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "velocity" ;
    rdfs:range midi:HexByte ;
    rdfs:comment "The velocity of a note message (0 to 127)." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"atom",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/atom>
    a lv2:Specification ;
    lv2:minorVersion 2 ;
    lv2:microVersion 2 ;
    rdfs:seeAlso <atom.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"atom.meta.ttl",
R"lv2ttl(@prefix atom: <http://lv2plug.in/ns/ext/atom#> .
@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/atom>
    a doap:Project ;
    doap:name "LV2 Atom" ;
    doap:shortdesc "A generic value container and several data types." ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:created "2007-00-00" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "2.2" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2_atom_object_get_typed() for easy type-safe access to object properties."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2014-08-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.10.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Deprecate Blank and Resource in favour of just Object."
            ] , [
                rdfs:label "Add lv2_atom_forge_is_object_type() and lv2_atom_forge_is_blank() to ease backwards compatibility."
            ] , [
                rdfs:label "Add lv2_atom_forge_key() for terser object writing."
            ] , [
                rdfs:label "Add lv2_atom_sequence_clear() and lv2_atom_sequence_append_event() helper functions."
            ]
        ]
    ] , [
        doap:revision "1.8" ;
        doap:created "2014-01-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.8.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Make lv2_atom_*_is_end() arguments const."
            ]
        ]
    ] , [
        doap:revision "1.6" ;
        doap:created "2013-05-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.6.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix crash in forge.h when pushing atoms to a full buffer."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2013-01-27" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix lv2_atom_sequence_end()."
            ] , [
                rdfs:label "Remove atom:stringType in favour of owl:onDatatype so generic tools can understand and validate atom literals."
            ] , [
                rdfs:label "Improve atom documentation."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix implicit conversions in forge.h that are invalid in C++11."
            ] , [
                rdfs:label "Fix lv2_atom_object_next() on 32-bit platforms."
            ] , [
                rdfs:label "Add lv2_atom_object_body_get()."
            ] , [
                rdfs:label "Fix outdated documentation in forge.h."
            ] , [
                rdfs:label "Use consistent label style."
            ] , [
                rdfs:label "Add LV2_ATOM_CONTENTS_CONST and LV2_ATOM_BODY_CONST."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

An atom:Atom is a simple generic data container for holding any type of Plain
Old Data (POD).  An Atom can contain simple primitive types like integers,
floating point numbers, and strings; as well as structured data like lists and
dictionary-like <q>Objects</q>.  Since Atoms are POD, they can be easily copied
(for example, with `memcpy()`) anywhere and are suitable for use in real-time
code.

Every atom starts with an LV2_Atom header, followed by the contents.  This
allows code to process atoms without requiring special code for every type of
data.  For example, plugins that mutually understand a type can be used
together in a host that does not understand that type, because the host is only
required to copy atoms, not interpret their contents.  Similarly, plugins (such
as routers, delays, or data structures) can meaningfully process atoms of a
type unknown to them.

Atoms should be used anywhere values of various types must be stored or
transmitted.  An atom:AtomPort can be used to transmit atoms via ports.  An
atom:AtomPort that contains a atom:Sequence can be used for sample accurate
communication of events, such as MIDI.

### Serialisation

Each Atom type defines a binary format for use at runtime, but also a
serialisation that is natural to express in Turtle format.  Thus, this
specification defines a powerful real-time appropriate data model, as well as a
portable way to serialise any data in that model.  This is particularly useful
for inter-process communication, saving/restoring state, and describing values
in plugin data files.

### Custom Atom Types

While it is possible to define new Atom types for any binary format, the
standard types defined here are powerful enough to describe almost anything.
Implementations SHOULD build structures out of the types provided here, rather
than define new binary formats (for example, using atom:Object rather than a
new C `struct` type).  Host and tool implementations have support for
serialising all standard types, so new binary formats are an implementation
burden which harms interoperabilty.  In particular, plugins SHOULD NOT expect
UI communication or state saving with custom binary types to work.  In general,
new Atom types should only be defined where absolutely necessary due to
performance reasons and serialisation is not a concern.

"""^^lv2:Markdown .

atom:Atom
    lv2:documentation """

An LV2_Atom has a 32-bit `size` and `type`, followed by a body of `size` bytes.
Atoms MUST be 64-bit aligned.

All concrete Atom types (subclasses of this class) MUST define a precise binary
layout for their body.

The `type` field is the URI of an Atom type mapped to an integer.
Implementations SHOULD gracefully pass through, or ignore, atoms with unknown
types.

All atoms are POD by definition except references, which as a special case have
`type` 0.  An Atom MUST NOT contain a Reference.  It is safe to copy any
non-reference Atom with a simple `memcpy`, even if the implementation does not
understand `type`.  Though this extension reserves the type 0 for references,
the details of reference handling are currently unspecified.  A future revision
of this extension, or a different extension, may define how to use non-POD data
and references.  Implementations MUST NOT send references to another
implementation unless the receiver is explicitly known to support references
(e.g. by supporting a feature).

The special case of a null atom with both `type` and `size` 0 is not considered
a reference.

"""^^lv2:Markdown .

atom:Chunk
    lv2:documentation """

This type is used to indicate a certain amount of space is available.  For
example, output ports with a variably sized type are connected to a Chunk so
the plugin knows the size of the buffer available for writing.

The use of a Chunk should be constrained to a local scope, since
interpreting it is impossible without context.  However, if serialised to RDF,
a Chunk may be represented directly as an xsd:base64Binary string, for example:

    :::turtle
    [] eg:someChunk "vu/erQ=="^^xsd:base64Binary .

"""^^lv2:Markdown .

atom:String
    lv2:documentation """

The body of an LV2_Atom_String is a C string in UTF-8 encoding, i.e. an array
of bytes (`uint8_t`) terminated with a NULL byte (`'\\0'`).

This type is for free-form strings, but SHOULD NOT be used for typed data or
text in any language.  Use atom:Literal unless translating the string does not
make sense and the string has no meaningful datatype.

"""^^lv2:Markdown .

atom:Literal
    lv2:documentation """

This type is compatible with rdfs:Literal and is capable of )lv2ttl" R"lv2ttl(expressing a
string in any language or a value of any type.  A Literal has a
`datatype` and `lang` followed by string data in UTF-8
encoding.  The length of the string data in bytes is `size -
sizeof(LV2_Atom_Literal)`, including the terminating NULL character.  The
`lang` field SHOULD be a URI of the form
`http://lexvo.org/id/iso639-3/LANG` or
`http://lexvo.org/id/iso639-1/LANG` where LANG is a 3-character ISO 693-3
language code, or a 2-character ISO 693-1 language code, respectively.

A Literal may have a `datatype` or a `lang`, but never both.

For example, a Literal can be <q>Hello</q> in English:

    :::c
    void set_to_hello_in_english(LV2_Atom_Literal* lit) {
         lit->atom.type     = map(expand("atom:Literal"));
         lit->atom.size     = 14;
         lit->body.datatype = 0;
         lit->body.lang     = map("http://lexvo.org/id/iso639-1/en");
         memcpy(LV2_ATOM_CONTENTS(LV2_Atom_Literal, lit),
                "Hello",
                sizeof("Hello"));  // Assumes enough space
    }

or a Turtle string:

    :::c
    void set_to_turtle_string(LV2_Atom_Literal* lit, const char* ttl) {
         lit->atom.type     = map(expand("atom:Literal"));
         lit->atom.size     = 64;
         lit->body.datatype = map("http://www.w3.org/2008/turtle#turtle");
         lit->body.lang     = 0;
         memcpy(LV2_ATOM_CONTENTS(LV2_Atom_Literal, lit),
                ttl,
                strlen(ttl) + 1);  // Assumes enough space
    }

"""^^lv2:Markdown .

atom:Path
    lv2:documentation """

A Path is a URI reference with only a path component: no scheme, authority,
query, or fragment.  In particular, paths to files in the same bundle may be
cleanly written in Turtle files as a relative URI.  However, implementations
may assume any binary Path (e.g. in an event payload) is a valid file path
which can passed to system functions like fopen() directly, without any
character encoding or escape expansion required.

Any implemenation that creates a Path atom to transmit to another is
responsible for ensuring it is valid.  A Path SHOULD always be absolute, unless
there is some mechanism in place that defines a base path.  Since this is not
the case for plugin instances, effectively any Path sent to or received from a
plugin instance MUST be absolute.

"""^^lv2:Markdown .

atom:URI
    lv2:documentation """

This is useful when a URI is needed but mapping is inappropriate, for example
with temporary or relative URIs.  Since the ability to distinguish URIs from
plain strings is often necessary, URIs MUST NOT be transmitted as atom:String.

This is not strictly a URI, since UTF-8 is allowed.  Escaping and related
issues are the host's responsibility.

"""^^lv2:Markdown .

atom:URID
    lv2:documentation """

A URID is typically generated with the LV2_URID_Map provided by the host .

"""^^lv2:Markdown .

atom:Vector
    lv2:documentation """

A homogeneous series of atom bodies with equivalent type and size.

An LV2_Atom_Vector is a 32-bit `child_size` and `child_type` followed by `size
/ child_size` atom bodies.

For example, an atom:Vector containing 42 elements of type atom:Float:

    :::c
    struct VectorOf42Floats {
        uint32_t size;        // sizeof(LV2_Atom_Vector_Body) + (42 * sizeof(float);
        uint32_t type;        // map(expand("atom:Vector"))
        uint32_t child_size;  // sizeof(float)
        uint32_t child_type;  // map(expand("atom:Float"))
        float    elems[42];
    };

Note that it is possible to construct a valid Atom for each element of the
vector, even by an implementation which does not understand `child_type`.

If serialised to RDF, a Vector SHOULD have the form:

    :::turtle
    eg:someVector
         a atom:Vector ;
         atom:childType atom:Int ;
         rdf:value (
             "1"^^xsd:int
             "2"^^xsd:int
             "3"^^xsd:int
             "4"^^xsd:int
         ) .

"""^^lv2:Markdown .

atom:Tuple
    lv2:documentation """

The body of a Tuple is simply a series of complete atoms, each aligned to
64 bits.

If serialised to RDF, a Tuple SHOULD have the form:

    :::turtle
    eg:someVector
         a atom:Tuple ;
         rdf:value (
             "1"^^xsd:int
             "3.5"^^xsd:float
             "etc"
         ) .

"""^^lv2:Markdown .

atom:Property
    lv2:documentation """

An LV2_Atom_Property has a URID `key` and `context`, and an Atom `value`.  This
corresponds to an RDF Property, where the <q>key</q> is the <q>predicate</q>
and the <q>value</q> is the object.

The `context` field can be used to specify a different context for each
property, where this is useful.  Otherwise, it may be 0.

Properties generally only exist as part of an atom:Object.  Accordingly,
they will typically be represented directly as properties in RDF (see
atom:Object).  If this is not possible, they may be expressed as partial
reified statements, for example:

    :::turtle
    eg:someProperty
        rdf:predicate eg:theKey ;
        rdf:object eg:theValue .

"""^^lv2:Markdown .

atom:Object
    lv2:documentation """

An <q>Object</q> is an atom with a set of properties.  This corresponds to an
RDF Resource, and can be thought of as a dictionary with URID keys.

An LV2_Atom_Object body has a uint32_t `id` and `type`, followed by a series of
atom:Property bodies (LV2_Atom_Property_Body).  The LV2_Atom_Object_Body::otype
field is equivalent to a property with key rdf:type, but is included in the
structure to allow for fast dispatching.

Code SHOULD check for objects using lv2_atom_forge_is_object() or
lv2_atom_forge_is_blank() if a forge is available, rather than checking the
atom type directly.  This will correctly handle the deprecated atom:Resource
and atom:Blank types.

When serialised to RDF, an Object is represented as a resource, for example:

    :::turtle
    eg:someObject
        eg:firstPropertyKey "first property value" ;
        eg:secondPropertyKey "first loser" ;
        eg:andSoOn "and so on" .

"""^^lv2:Markdown .

atom:Resource
    lv2:documentation """

This class is deprecated.  Use atom:Object directly instead.

An atom:Object where the <code>id</code> field is a URID, that is, an Object
with a URI.

"""^^lv2:Markdown .

atom:Blank
    lv2:documentation """

This class is deprecated.  Use atom:Object with ID 0 instead.

An atom:Object where the LV2_Atom_Object::id is a blank node ID (NOT a URI).
The ID of a Blank is valid only within the context the Blank appears in.  For
ports this is the context of the associated run() call, i.e. all ports share
the same context so outputs can contain IDs that correspond to IDs of blanks in
the input.

"""^^lv2:Markdown .

atom:Sound
    lv2:documentation """

The format of a atom:Sound is the same as the buffer format for lv2:AudioPort
(except the size may be arbitrary).  An atom:Sound inherently depends on the
sample rate, which is assumed to be known from context.  Because of this,
directly serialising an atom:Sound is probably a bad idea, use a standard
format like WAV instead.

"""^^lv2:Markdown .

atom:Event
    lv2:documentation """

An Event is typically an element of an atom:Sequence.  Note that this is not an Atom type since it begins with a timestamp, not an atom header.

"""^^lv2:Markdown .

atom:Sequence
    lv2:documentation """

A flat sequence of atom:Event, that is, a series of time-stamped Atoms.

LV2_Atom_Sequence_Body.unit describes the time unit for the contained atoms.
If the unit is known from context (e.g. run() stamps are always audio frames),
this field may be zero.  Otherwise, it SHOULD be either units:frame or
units:beat, in which case ev.time.frames or ev.time.beats is valid,
respectively.

If serialised to RDF, a Sequence has a similar form to atom:Vector, but for
brevity the elements may be assumed to be atom:Event, for example:

    :::turtle
    eg:someSequence
        a atom:Sequence ;
        rdf:value (
            [
                atom:frameTime 1 ;
                rdf:value "901A01"^^midi:MidiEvent
            ] [
                atom:frame)lv2ttl" R"lv2ttl(Time 3 ;
                rdf:value "902B02"^^midi:MidiEvent
            ]
        ) .

"""^^lv2:Markdown .

atom:AtomPort
    lv2:documentation """

Ports of this type are connected to an LV2_Atom with a type specified by
atom:bufferType.

Output ports with a variably sized type MUST be initialised by the host before
every run() to an atom:Chunk with size set to the available space.  The plugin
reads this size to know how much space is available for writing.  In all cases,
the plugin MUST write a complete atom (including header) to outputs.  However,
to be robust, hosts SHOULD initialise output ports to a safe sentinel (e.g. the
null Atom) before calling run().

"""^^lv2:Markdown .

atom:bufferType
    lv2:documentation """

Indicates that an AtomPort may be connected to a certain Atom type.  A port MAY
support several buffer types.  The host MUST NOT connect a port to an Atom with
a type not explicitly listed with this property.  The value of this property
MUST be a sub-class of atom:Atom.  For example, an input port that is connected
directly to an LV2_Atom_Double value is described like so:

    :::turtle
    <plugin>
        lv2:port [
            a lv2:InputPort , atom:AtomPort ;
            atom:bufferType atom:Double ;
        ] .

This property only describes the types a port may be directly connected to.  It
says nothing about the expected contents of containers.  For that, use
atom:supports.

"""^^lv2:Markdown .

atom:supports
    lv2:documentation """

This property is defined loosely, it may be used to indicate that anything
<q>supports</q> an Atom type, wherever that may be useful.  It applies
<q>recursively</q> where collections are involved.

In particular, this property can be used to describe which event types are
expected by a port.  For example, a port that receives MIDI events is described
like so:

    :::turtle
    <plugin>
        lv2:port [
            a lv2:InputPort , atom:AtomPort ;
            atom:bufferType atom:Sequence ;
            atom:supports midi:MidiEvent ;
        ] .

"""^^lv2:Markdown .

atom:eventTransfer
    lv2:documentation """

Transfer of individual events in a port buffer.  Useful as the `format` for a
LV2UI_Write_Function.

This protocol applies to ports which contain events, usually in an
atom:Sequence.  The host must transfer each individual event to the recipient.
The format of the received data is an LV2_Atom, there is no timestamp header.

"""^^lv2:Markdown .

atom:atomTransfer
    lv2:documentation """

Transfer of the complete atom in a port buffer.  Useful as the `format` for a
LV2UI_Write_Function.

This protocol applies to atom ports.  The host must transfer the complete atom
contained in the port, including header.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"atom.ttl",
R"lv2ttl(@prefix atom: <http://lv2plug.in/ns/ext/atom#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix ui: <http://lv2plug.in/ns/extensions/ui#> .
@prefix units: <http://lv2plug.in/ns/extensions/units#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/atom>
    a owl:Ontology ;
    rdfs:seeAlso <atom.h> ,
        <util.h> ,
        <forge.h> ,
        <atom.meta.ttl> ;
    rdfs:label "LV2 Atom" ;
    rdfs:comment "A generic value container and several data types." .

atom:cType
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "C type" ;
    rdfs:comment "The C type that describes the binary representation of an Atom type." ;
    rdfs:domain rdfs:Class ;
    rdfs:range lv2:Symbol .

atom:Atom
    a rdfs:Class ;
    rdfs:label "Atom" ;
    rdfs:comment "Abstract base class for all atoms." ;
    atom:cType "LV2_Atom" .

atom:Chunk
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Chunk" ;
    rdfs:comment "A chunk of memory with undefined contents." ;
    owl:onDatatype xsd:base64Binary .

atom:Number
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Number" ;
    rdfs:comment "Base class for numeric types." .

atom:Int
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Number ;
    rdfs:label "Int" ;
    rdfs:comment "A native `int32_t`." ;
    atom:cType "LV2_Atom_Int" ;
    owl:onDatatype xsd:int .

atom:Long
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Number ;
    rdfs:label "Long" ;
    rdfs:comment "A native `int64_t`." ;
    atom:cType "LV2_Atom_Long" ;
    owl:onDatatype xsd:long .

atom:Float
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Number ;
    rdfs:label "Float" ;
    rdfs:comment "A native `float`." ;
    atom:cType "LV2_Atom_Float" ;
    owl:onDatatype xsd:float .

atom:Double
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Number ;
    rdfs:label "Double" ;
    rdfs:comment "A native `double`." ;
    atom:cType "LV2_Atom_Double" ;
    owl:onDatatype xsd:double .

atom:Bool
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Bool" ;
    rdfs:comment "An atom:Int where 0 is false and any other value is true." ;
    atom:cType "LV2_Atom_Bool" ;
    owl:onDatatype xsd:boolean .

atom:String
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "String" ;
    rdfs:comment "A UTF-8 string." ;
    atom:cType "LV2_Atom_String" ;
    owl:onDatatype xsd:string .

atom:Literal
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Literal" ;
    rdfs:comment "A UTF-8 string literal with optional datatype or language." ;
    atom:cType "LV2_Atom_Literal" .

atom:Path
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:URI ;
    owl:onDatatype atom:URI ;
    rdfs:label "Path" ;
    rdfs:comment "A local file path." .

atom:URI
    a rdfs:Class ,
        rdfs:Datatype ;
    rdfs:subClassOf atom:String ;
    owl:onDatatype xsd:anyURI ;
    rdfs:label "URI" ;
    rdfs:comment "A URI string." .

atom:URID
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "URID" ;
    rdfs:comment "An unsigned 32-bit integer ID for a URI." ;
    atom:cType "LV2_Atom_URID" .

atom:Vector
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Vector" ;
    rdfs:comment "A homogeneous sequence of atom bodies with equivalent type and size." ;
    atom:cType "LV2_Atom_Vector" .

atom:Tuple
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Tuple" ;
    rdfs:comment "A sequence of atoms with varying type and size." .

atom:Property
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Property" ;
    rdfs:comment "A property of an atom:Object." ;
    atom:cType "LV2_Atom_Property" .

atom:Object
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Object" ;
    rdfs:comment "A collection of properties." ;
    atom:cType "LV2_Atom_Object" .

atom:Resource
    a rdfs:Class ;
    rdfs:subClassOf atom:Object ;
    rdfs:label "Resource" ;
    rdfs:comment "A named collection of properties with a URI." ;
    owl:deprecated "true"^^xsd:boolean ;
    atom:cType "LV2_Atom_Object" .

atom:Blank
    a rdfs:Class ;
    rdfs:subClassOf atom:Object ;
    rdfs:label "Blank" ;
    rdfs:comment "An anonymous collection of properties without a URI." ;
    owl:deprecated "true"^^xsd:boolean ;
    atom:cType "LV2_Atom_Object" .

atom:Sound
    a rdfs:Class ;
    rdfs:subClassOf atom:Vector ;
    rdfs:label "Sound" ;
    rdfs:comment "A atom:Vector of atom:Float which represents an audio waveform." ;
    atom:cType "LV2_Atom_Vector" .

atom:frameTime
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:range xsd:decimal ;
    rdfs:label "frame time" ;
    rdfs:comment "A time stamp in audio frames." .

atom:beatTime
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:range xsd:decimal ;
    rdfs:label "beat time" ;
    rdfs:comment "A time stamp in beats." .

atom:Event
    a rdfs:Class ;
    rdfs:label "Event" ;
    atom:cType "LV2_Atom_Event" ;
    rdfs:comment "An atom with a time stamp prefix in a sequence." .

atom:Sequence
    a rdfs:Class ;
    rdfs:subClassOf atom:Atom ;
    rdfs:label "Sequence" ;
    atom:cType "LV2_Atom_Sequence" ;
    rdfs:comment "A sequence of events." .

atom:AtomPort
    a rdfs:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Atom Port" ;
    rdfs:comment "A port which contains an atom:Atom." .

atom:bufferType
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain atom:AtomPort ;
    rdfs:range rdfs:Class ;
    rdfs:label "buffer type" ;
    rdfs:comment "An atom type that a port may be connected to." .

atom:childType
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "child type" ;
    rdfs:comment "The type of children in a container." .

atom:supports
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "supports" ;
    rdfs:comment "A supported atom type." ;
    rdfs:range rdfs:Class .

atom:eventTransfer
    a ui:PortProtocol ;
    rdfs:label "event transfer" ;
    rdfs:comment "A port protocol for transferring events." .

atom:atomTransfer
    a ui:PortProtocol ;
    rdfs:label "atom transfer" ;
    rdfs:comment "A port protocol for transferring atoms." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"buf-size",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/buf-size>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 4 ;
    rdfs:seeAlso <buf-size.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"buf-size.meta.ttl",
R"lv2ttl(@prefix bufsz: <http://lv2plug.in/ns/ext/buf-size#> .
@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/buf-size>
    a doap:Project ;
    doap:name "LV2 Buf Size" ;
    doap:shortdesc "Access to, and restrictions on, buffer sizes." ;
    doap:created "2012-08-07" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.4" ;
        doap:created "2015-09-18" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add bufsz:nominalBlockLength option."
            ] , [
                rdfs:label "Add bufsz:coarseBlockLength feature."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-12-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix typo in bufsz:sequenceSize label."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a facility for plugins to get information about the
block length (the sample_count parameter of LV2_Descriptor::run) and port
buffer sizes, as well as several features which can be used to restrict the
block length.

This extension defines features and properties but has no special purpose
API of its own.  The host provides all the relevant information to the plugin
as [options](options.html).

To require restrictions on the block length, plugins can require additional
features: bufsz:boundedBlockLength, bufsz:powerOf2BlockLength, and
bufsz:fixedBlockLength.  These features are data-only, that is they merely
indicate a restriction and do not carry any data or API.

"""^^lv2:Markdown .

bufsz:boundedBlockLength
    lv2:documentation """

A feature that indicates the host will provide both the bufsz:minBlockLength
and bufsz:maxBlockLength options to the plugin.  Plugins that copy data from
audio inputs can require this feature to ensure they know how much space is
required for auxiliary buffers.  Note the minimum may be zero, this feature is
mainly useful to ensure a maximum is available.

All hosts SHOULD support this feature, since it is simple to support and
necessary for any plugins that may need to copy the input.

"""^^lv2:Markdown .

bufsz:fixedBlockLength
    lv2:documentation """

A feature that indicates the host will always call LV2_Descriptor::run() with
the same value for sample_count.  This length MUST be provided as the value of
both the bufsz:minBlockLength and bufsz:maxBlockLength options.

Note that requiring this feature may severely limit the number of hosts capable
of running the plugin.

"""^^lv2:Markdown .

bufsz:powerOf2BlockLength
    lv2:documentation """

A feature that indicates the host will always call LV2_Descriptor::run() with a
power of two sample_count.  Note that this feature does not guarantee the value
is the same each call, to guarantee a fixed power of two block length plugins
must require both this feature and bufsz:fixedBlockLength.

Note that requiring this feature may severely limit the number of hosts capable
of running the plugin.

"""^^lv2:Markdown .

bufsz:coarseBlockLength
    lv2:documentation """

A feature that indicates the plugin prefers coarse, regular block lengths.  For
example, plugins that do not implement sample-accurate control use this feature
to indicate that the host should not split the run cycle because controls have
changed.

Note that this feature is merely a hint, and does not guarantee a fixed block
length.  The run cycle may be split for other reasons, and the blocksize itself
may change anytime.

"""^^lv2:Markdown .

bufsz:maxBlockLength
    lv2:documentation """

The maximum block length the host will ever request the plugin to process at
once, that is, the maximum `sample_count` parameter that will ever be passed to
LV2_Descriptor::run().

"""^^lv2:Markdown .

bufsz:minBlockLength
    lv2:documentation """

The minimum block length the host will ever request the plugin to process at
once, that is, the minimum `sample_count` parameter that will ever be passed to
LV2_Descriptor::run().

"""^^lv2:Markdown .

bufsz:nominalBlockLength
    lv2:documentation """

The typical block length the host will request the plugin to process at once,
that is, the typical `sample_count` parameter that will be passed to
LV2_Descriptor::run().  This will usually be equivalent, or close to, the
maximum block length, but there are no strong guarantees about this value
whatsoever.  Plugins may use this length for optimization purposes, but MUST
NOT assume the host will always process blocks of this length.  In particular,
the host MAY process longer blocks.

"""^^lv2:Markdown .

bufsz:sequenceSize
    lv2:documentation """

This should be provided as an option by hosts that support event ports
(including but not limited to MIDI), so plugins have the ability to allocate
auxiliary buffers large enough to copy the input.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"buf-size.ttl",
R"lv2ttl(@prefix bufsz: <http://lv2plug.in/ns/ext/buf-size#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix opts: <http://lv2plug.in/ns/ext/options#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/buf-size>
    a owl:Ontology ;
    rdfs:label "LV2 Buf Size" ;
    rdfs:comment "Access to, and restrictions on, buffer sizes." ;
    rdfs:seeAlso <buf-size.h> ,
        <buf-size.meta.ttl> .

bufsz:boundedBlockLength
    a lv2:Feature ;
    rdfs:label "bounded block length" ;
    rdfs:comment "Block length has lower and upper bounds." .

bufsz:fixedBlockLength
    a lv2:Feature ;
    rdfs:label "fixed block length" ;
    rdfs:comment "Block length never changes." .

bufsz:powerOf2BlockLength
    a lv2:Feature ;
    rdfs:label "power of 2 block length" ;
    rdfs:comment "Block length is a power of 2." .

bufsz:coarseBlockLength
    a lv2:Feature ;
    rdfs:label "coarse block length" ;
    rdfs:comment "Plugin prefers coarse block length without buffer splitting." .

bufsz:maxBlockLength
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:label "maximum block length" ;
    rdfs:comment "Block length has an upper bound." ;
    rdfs:range xsd:nonNegativeInteger .

bufsz:minBlockLength
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:label "minimum block length" ;
    rdfs:comment "Block length has a lower bound." ;
    rdfs:range xsd:nonNegativeInteger .

bufsz:nominalBlockLength
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:label "nominal block length" ;
    rdfs:comment "Typical block length that will most often be processed." ;
    rdfs:range xsd:nonNegativeInteger .

bufsz:sequenceSize
    a rdf:Property ,
        owl:DatatypeProperty ,
        opts:Option ;
    rdfs:label "sequence size" ;
    rdfs:comment "The maximum size of a sequence, in bytes." ;
    rdfs:range xsd:nonNegativeInteger .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"morph",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/morph>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 0 ;
    rdfs:seeAlso <morph.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"morph.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix morph: <http://lv2plug.in/ns/ext/morph#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/morph>
    a doap:Project ;
    doap:name "LV2 Morph" ;
    doap:shortdesc "Ports that can dynamically change type." ;
    doap:created "2012-05-22" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.0" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines two port types: morph:MorphPort, which has a
host-configurable type, and morph:AutoMorphPort, which may automatically change
type when a MorphPort's type is changed.  These ports always have a default
type and work normally work in hosts that are unaware of this extension.  Thus,
this extension provides a backwards compatibility mechanism which allows
plugins to use new port types but gracefully fall back to a default type in
hosts that do not support them.

This extension only defines port types and properties for describing morph
ports.  The actual run-time switching is done via the opts:interface API.

"""^^lv2:Markdown .

morph:MorphPort
    lv2:documentation """

Ports of this type MUST have another type which defines the default buffer
format (for example lv2:ControlPort) but can be dynamically changed to a
different type in hosts that support opts:interface.

The host may change the type of a MorphPort by setting its morph:currentType
with LV2_Options_Interface::set().  If the plugin has any morph:AutoMorphPort
ports, the host MUST check their types after changing any port type since they
may have changed.

"""^^lv2:Markdown .

morph:AutoMorphPort
    lv2:documentation """

Ports of this type MUST have another type which defines the default buffer
format (for example, lv2:ControlPort) but may dynamically change types based on
the configured types of any morph:MorphPort ports on the same plugin instance.

The type of a port may only change in response to a host call to
LV2_Options_Interface::set().  Whenever any port type on the instance changes,
the host MUST check the type of all morph:AutoMorphPort ports with
LV2_Options_Interface::get() before calling run() again, since they may have
changed.  If the type of any port is zero, it means the current configuration
is invalid and the plugin may not be run (unless that port is
lv2:connectionOptional and connected to NULL).

This is mainly useful for outputs whose type depends on the type of
corresponding inputs.

"""^^lv2:Markdown .

morph:supportsType
    lv2:documentation """

Indicates that a port supports being switched to a certain type.  A MorphPort
MUST list each type it supports being switched to in the plugin data using this
property.

"""^^lv2:Markdown .

morph:currentType
    lv2:documentation """

The currently active type of the port.  This is for dynamic use as an option
and SHOULD NOT be listed in the static plugin data.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"morph.ttl",
R"lv2ttl(@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix morph: <http://lv2plug.in/ns/ext/morph#> .
@prefix opts: <http://lv2plug.in/ns/ext/options#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/morph>
    a owl:Ontology ;
    rdfs:label "LV2 Morph" ;
    rdfs:comment "Ports that can dynamically change type." ;
    rdfs:seeAlso <morph.h> ,
        <morph.meta.ttl> .

morph:MorphPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Morph Port" ;
    rdfs:comment "A port which can be switched to another type." .

morph:AutoMorphPort
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf lv2:Port ;
    rdfs:label "Auto Morph Port" ;
    rdfs:comment "A port that can change its type based on that of another." .

morph:supportsType
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain morph:MorphPort ;
    rdfs:label "supports type" ;
    rdfs:comment "A type that a port supports being switched to." .

morph:currentType
    a rdf:Property ,
        opts:Option ,
        owl:ObjectProperty ;
    rdfs:domain morph:MorphPort ;
    rdfs:label "current type" ;
    rdfs:comment "The currently active type of the port." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"state",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/state>
    a lv2:Specification ;
    lv2:minorVersion 2 ;
    lv2:microVersion 8 ;
    rdfs:seeAlso <state.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"state.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix state: <http://lv2plug.in/ns/ext/state#> .

<http://lv2plug.in/ns/ext/state>
    a owl:Ontology ;
    rdfs:label "LV2 State" ;
    rdfs:comment "An interface for LV2 plugins to save and restore state." ;
    rdfs:seeAlso <state.h> ,
        <state.meta.ttl> .

state:interface
    a lv2:ExtensionData ;
    rdfs:label "interface" ;
    rdfs:comment "A plugin interface for saving and restoring state." .

state:State
    a rdfs:Class ;
    rdfs:label "State" ;
    rdfs:comment "LV2 plugin state." .

state:loadDefaultState
    a lv2:Feature ;
    rdfs:label "load default state" ;
    rdfs:comment "A feature indicating that the plugin has default state." .

state:state
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "state" ;
    rdfs:range state:State ;
    rdfs:comment "The state of an LV2 plugin instance." .

state:mapPath
    a lv2:Feature ;
    rdfs:label "map path" ;
    rdfs:comment "A feature for mapping between absolute and abstract file paths." .

state:makePath
    a lv2:Feature ;
    rdfs:label "make path" ;
    rdfs:comment "A feature for creating new files and directories." .

state:threadSafeRestore
    a lv2:Feature ;
    rdfs:label "thread-safe restore" ;
    rdfs:comment "A feature indicating support for thread-safe state restoration." .

state:freePath
    a lv2:Feature ;
    rdfs:label "free path" ;
    rdfs:comment "A feature for freeing paths allocated by the host." .

state:StateChanged
    a rdfs:Class ;
    rdfs:label "State Changed" ;
    rdfs:comment "A notification that the internal state of the plugin has changed." .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"state.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix state: <http://lv2plug.in/ns/ext/state#> .

<http://lv2plug.in/ns/ext/state>
    a doap:Project ;
    doap:created "2010-11-09" ;
    doap:name "LV2 State" ;
    doap:shortdesc "An interface for LV2 plugins to save and restore state." ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:developer <http://lv2plug.in/ns/meta#paniq> ,
        <http://drobilla.net/drobilla#me> ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "2.8" ;
        doap:created "2021-01-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix state:StateChanged URI in metadata and documentation."
            ]
        ]
    ] , [
        doap:revision "2.6" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add state:freePath feature."
            ]
        ]
    ] , [
        doap:revision "2.4" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add state:StateChanged for notification events."
            ]
        ]
    ] , [
        doap:revision "2.2" ;
        doap:created "2016-07-31" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add LV2_STATE_ERR_NO_SPACE status flag."
            ] , [
                rdfs:label "Add state:threadSafeRestore feature for dropout-free state restoration."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2013-01-16" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add state:loadDefaultState feature so plugins can have their default state loaded without hard-coding default state as a special case."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a simple mechanism that allows hosts to save and restore
a plugin instance's state.  The goal is for an instance's state to be
completely described by port values and a simple dictionary.

The <q>state</q> defined here is conceptually a key:value dictionary, with URI keys
and values of any type. For performance reasons the key and value type are
actually a "URID", a URI mapped to an integer. A single key:value pair is
called a "property".

This state model is simple yet has many benefits:

  * Both fast and extensible thanks to URID keys.

  * No limitations on possible value types.

  * Easy to serialise in almost any format.

  * Easy to store in a typical "map" or "dictionary" data structure.

  * Elegantly described in Turtle, so state can be described in LV2 data files
    (including presets).

  * Does not impose any file formats, data structures, or file system
    requirements.

  * Suitable for portable persistent state as well as fast in-memory snapshots.

  * Keys _may_ be well-defined and used meaningfully across several
    implementations.

  * State _may_ be dynamic, but plugins are not required to have a dynamic
    dictionary data structure available.

To implement state, the plugin provides a state:interface to the host. To save
or restore, the host calls LV2_State_Interface::save() or
LV2_State_Interface::restore(), passing a callback to be used for handling a
single property. The host is free to implement property storage and retrieval
in any way.

Since value types are defined by URI, any type is possible. However, a set of
standard types is defined by the [LV2 Atom](atom.html) extension. Use of these
types is recommended. Hosts MUST implement at least
[atom:String](atom.html#String), which is simply a C string.

### Referring to Files

Plugins may need to refer to existing files (such as loaded samples) in their
state. This is done by storing the file's path as a property just like any
other value. However, there are some rules which MUST be followed when storing
paths, see state:mapPath for details. Plugins MUST use the type
[atom:Path](atom.html#Path) for all paths in their state.

Plugins are strongly encouraged to avoid creating files, instead storing all
state as properties. However, occasionally the ability to create files is
necessary. To make this possible, the host can provide the feature
state:makePath which allocates paths for plugin-created files. Plugins MUST
NOT create files in any other locations.

### Plugin Code Example

    :::c

    /* Namespace for this plugin's keys.  This SHOULD be something that could be
       published as a document, even if that document does not exist right now.
    */
    #define NS_MY "http://example.org/myplugin/schema#"

    #define DEFAULT_GREETING "Hello"

    LV2_Handle
    my_instantiate(...)
    {
        MyPlugin* plugin = ...;
        plugin->uris.atom_String = map_uri(LV2_ATOM__String);
        plugin->uris.my_greeting = map_uri(NS_MY "greeting");
        plugin->state.greeting   = strdup(DEFAULT_GREETING);
        return plugin;
    }

    LV2_State_Status
    my_save(LV2_Handle                 instance,
            LV2_State_Store_Function   store,
            LV2_State_Handle           handle,
            uint32_t                   flags,
            const LV2_Feature *const * features)
    {
        MyPlugin*   plugin   = (MyPlugin*)instance;
        const char* greeting = plugin->state.greeting;

        store(handle,
              plugin->uris.my_greeting,
              greeting,
              strlen(greeting) + 1,  // Careful!  Need space for terminator
              plugin->uris.atom_String,
              LV2_STATE_IS_POD | LV2_STATE_IS_PORTABLE);

        return LV2_STATE_SUCCESS;
    }

    LV2_State_Status
    my_restore(LV2_Handle                  instance,
               LV2_State_Retrieve_Function retrieve,
               LV2_State_Handle            handle,
               uint32_t                    flags,
               const LV2_Feature *const *  features)
    {
        MyPlugin* plugin = (MyPlugin*)instance;

        size_t      size;
        uint32_t    type;
        uint32_t    flags;
        const char* greeting = retrieve(
            handle, plugin->uris.my_greeting, &size, &type, &flags);

        if (greeting) {
            free(plugin->state->greeting);
            plugin->state->greeting = strdup(greeting);
        } else {
            plugin->state->greeting = strdup(DEFAULT_GREETING);
        }

        return LV2_STATE_SUCCESS;
    }

    const void*
    my_extension_data(const char* uri)
    {
        static const LV2_State_Interface state_iface = { my_save, my_restore };
        if (!strcmp(uri, LV2_STATE__interface)) {
            return &state_iface;
        }
    }

### Host Code Example

    :::c
    LV2_State_Status
    store_callback(LV2_State_Handle handle,
                   uint32_t         key,
                   const void*      value,
                   size_t           size,
                   uint32_t         type,
                   uint32_t         flags)
    {
        if ((flags & LV2_STATE_IS_POD)) {
            // We only care about POD since we're keeping sta)lv2ttl" R"lv2ttl(te in memory only.
            // Disk or network use would also require LV2_STATE_IS_PORTABLE.
            Map* state_map = (Map*)handle;
            state_map->insert(key, Value(copy(value), size, type));
            return LV2_STATE_SUCCESS;;
        } else {
            return LV2_STATE_ERR_BAD_FLAGS; // Non-POD events are unsupported
        }
    }

    Map
    get_plugin_state(LV2_Handle instance)
    {
        LV2_State* state = instance.extension_data(LV2_STATE__interface);

        // Request a fast/native/POD save, since we're just copying in memory
        Map state_map;
        state.save(instance, store_callback, &state_map,
                   LV2_STATE_IS_POD|LV2_STATE_IS_NATIVE);

        return state_map;
    }

### Extensions to this Specification

It is likely that other interfaces for working with plugin state will be
developed as needed. This is encouraged, however everything SHOULD work within
the state _model_ defined here. That is, **do not complicate the state
model**. Implementations can assume the following:

  * The current port values and state dictionary completely describe a plugin
    instance, at least well enough that saving and restoring will yield an
    "identical" instance from the user's perspective.

  * Hosts are not expected to save and/or restore any other attributes of a
    plugin instance.

### The "Property Principle"

The main benefit of this meaningful state model is that it can double as a
plugin control/query mechanism. For plugins that require more advanced control
than simple control ports, instead of defining a set of commands, define
properties whose values can be set appropriately. This provides both a way to
control and save that state "for free", since there is no need to define
commands _and_ a set of properties for storing their effects. In particular,
this is a good way for UIs to achieve more advanced control of plugins.

This "property principle" is summed up in the phrase: "Don't stop; set playing
to false".

This extension does not define a dynamic mechanism for state access and
manipulation. The [LV2 Patch](patch.html) extension defines a generic set of
messages which can be used to access or manipulate properties, and the [LV2
Atom](atom.html) extension defines a port type and data container capable of
transmitting those messages.

"""^^lv2:Markdown .

state:interface
    lv2:documentation """

A structure (LV2_State_Interface) which contains functions to be called by the
host to save and restore state.  In order to support this extension, the plugin
must return a valid LV2_State_Interface from LV2_Descriptor::extension_data()
when it is called with URI LV2_STATE__interface.

The plugin data file should describe this like so:

    :::turtle
    @prefix state: <http://lv2plug.in/ns/ext/state#> .

    <plugin>
        a lv2:Plugin ;
        lv2:extensionData state:interface .

"""^^lv2:Markdown .

state:State
    lv2:documentation """

This type should be used wherever instance state is described.  The properties
of a resource with this type correspond directly to the properties of the state
dictionary (except the property that states it has this type).

"""^^lv2:Markdown .

state:loadDefaultState
    lv2:documentation """

This feature indicates that the plugin has default state listed with the
state:state property which should be loaded by the host before running the
plugin.  Requiring this feature allows plugins to implement a single state
loading mechanism which works for initialisation as well as restoration,
without having to hard-code default state.

To support this feature, the host MUST restore the default state after
instantiating the plugin but before calling run().

"""^^lv2:Markdown .

state:state
    lv2:documentation """

This property may be used anywhere a state needs to be described, for example:

    :::turtle
    @prefix eg: <http://example.org/> .

    <plugin-instance>
        state:state [
            eg:somekey "some value" ;
            eg:someotherkey "some other value" ;
            eg:favourite-number 2
        ] .

"""^^lv2:Markdown .

state:mapPath
    lv2:documentation """

This feature maps absolute paths to/from <q>abstract paths</q> which are stored
in state.  To support this feature a host must pass an LV2_Feature with URI
LV2_STATE__mapPath and data pointed to an LV2_State_Map_Path to the plugin's
LV2_State_Interface methods.

The plugin MUST map _all_ paths stored in its state (including those inside any
files).  This is necessary so that hosts can handle file system references
correctly, for example to share common files, or bundle state for distribution
or archival.

For example, a plugin may write a path to a state file like so:

    :::c
    void write_path(LV2_State_Map_Path* map_path, FILE* myfile, const char* path)
    {
        char* abstract_path = map_path->abstract_path(map_path->handle, path);
        fprintf(myfile, "%s", abstract_path);
        free(abstract_path);
    }

Then, later reload the path like so:

    :::c
    char* read_path(LV2_State_Map_Path* map_path, FILE* myfile)
    {
        /* Obviously this is not production quality code! */
        char abstract_path[1024];
        fscanf(myfile, "%s", abstract_path);
        return map_path->absolute_path(map_path->handle, abstract_path);
    }

"""^^lv2:Markdown .

state:makePath
    lv2:documentation """

This feature allows plugins to create new files and/or directories.  To support
this feature the host passes an LV2_Feature with URI LV2_STATE__makePath and
data pointed to an LV2_State_Make_Path to the plugin.  The host may make this
feature available only during save by passing it to
LV2_State_Interface::save(), or available any time by passing it to
LV2_Descriptor::instantiate().  If passed to LV2_State_Interface::save(), the
feature MUST NOT be used beyond the scope of that call.

The plugin is guaranteed a hierarchical namespace unique to that plugin
instance, and may expect the returned path to have the requested path as a
suffix.  There is one such namespace, even if the feature is passed to both
LV2_Descriptor::instantiate() and LV2_State_Interface::save().  Beyond this,
the plugin MUST NOT make any assumptions about the returned paths.

Like any other paths, the plugin MUST map these paths using state:mapPath
before storing them in state.  The plugin MUST NOT assume these paths will be
available across a save/restore otherwise, that is, only mapped paths saved to
state are persistent, any other created paths are temporary.

For example, a plugin may create a file in a subdirectory like so:

    :::c
    char* save_myfile(LV2_State_Make_Path* make_path)
    {
        char* path   = make_path->path(make_path->handle, "foo/bar/myfile.txt");
        FILE* myfile = fopen(path, 'w');
        fprintf(myfile, "I am some data");
        fclose(myfile);
        return path;
    }

"""^^lv2:Markdown .

state:threadSafeRestore
    lv2:documentation """

If a plugin supports this feature, its LV2_State_Interface::restore method is
thread-safe and may be called concurrently with audio class functions.

To support this feature, the host MUST pass a
[work:schedule](worker.html#schedule) feature to the restore method, which will
be used to complete the state restoration.  The usual mechanics of the worker
apply: the host will call the plugin's work method, which emits a response
which is later applied in the audio thread.

The host is not required to block audio processing while restore() and work()
load the state, so this feature allows state to be restored without dropouts.

"""^^lv2:Markdown .

state:freePath
    lv2:documentation """

This feature provides a function that can be used by plugins to free paths that
were allocated by the host via other state features (state:mapPath and
state:makePath).

"""^^lv2:Markdown .

state:StateChanged
    lv2:documentation """

A notification that the internal state of the plugin has been changed in a way
that the host can not otherwise know about.

This is a one-way)lv2ttl" R"lv2ttl( notification, intended to be used as the type of an
[Object](atom.html#Object) sent from plugins when necessary.

Plugins SHOULD emit such an event whenever a change has occurred that would
result in a different state being saved, but not when the host explicity makes
a change which it knows is likely to have that effect, such as changing a
parameter.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"time",
{
juce::lv2::BundleResource
{
"time.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix time: <http://lv2plug.in/ns/ext/time#> .

<http://lv2plug.in/ns/ext/time>
    a doap:Project ;
    doap:name "LV2 Time" ;
    doap:shortdesc "A vocabulary for describing musical time." ;
    doap:created "2011-10-05" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.6" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Clarify time:beat origin."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2016-07-31" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Define LV2_TIME_PREFIX."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This is a vocabulary for describing a position in time and the speed of time
passage, in both real and musical terms.

In addition to real time (based on seconds), two units of time are used:
_frames_ and _beats_.  A frame is a numbered quantum of time.  Frame time is
related to real-time by the _frame rate_ or _sample rate_,
time:framesPerSecond.  A beat is a single pulse of musical time.  Beat time is
related to real-time by the _tempo_, time:beatsPerMinute.

Musical time additionally has a _meter_ which describes passage of time in
terms of musical _bars_.  A bar is a higher level grouping of beats.  The meter
describes how many beats are in one bar.

"""^^lv2:Markdown .

time:Position
    lv2:documentation """

A point in time and/or the speed at which time is passing.  A position is both
a point and a speed, which precisely defines a time within a timeline.

"""^^lv2:Markdown .

time:Rate
    lv2:documentation """

The rate of passage of time in terms of one unit with respect to another.

"""^^lv2:Markdown .

time:beat
    lv2:documentation """

This is not the beat within a bar like time:barBeat, but relative to the same
origin as time:bar and monotonically increases unless the transport is
repositioned.

"""^^lv2:Markdown .

time:beatUnit
    lv2:documentation """

Beat unit, the note value that counts as one beat.  This is the bottom number
in a time signature: 2 for half note, 4 for quarter note, and so on.

"""^^lv2:Markdown .

time:speed
    lv2:documentation """

The rate of the progress of time as a fraction of normal speed.  For example, a
rate of 0.0 is stopped, 1.0 is rolling at normal speed, 0.5 is rolling at half
speed, -1.0 is reverse, and so on.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/time>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 6 ;
    rdfs:seeAlso <time.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"time.ttl",
R"lv2ttl(@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix time: <http://lv2plug.in/ns/ext/time#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/time>
    a owl:Ontology ;
    rdfs:label "LV2 Time" ;
    rdfs:comment "A vocabulary for describing musical time." ;
    rdfs:seeAlso <time.h> ,
        <time.meta.ttl> .

time:Time
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf time:Position ;
    rdfs:label "Time" ;
    rdfs:comment "A point in time in some unit/dimension." .

time:Position
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Position" ;
    rdfs:comment "A point in time and/or the speed at which time is passing." .

time:Rate
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf time:Position ;
    rdfs:label "Rate" ;
    rdfs:comment "The rate of passage of time." .

time:position
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:range time:Position ;
    rdfs:label "position" ;
    rdfs:comment "A musical position." .

time:barBeat
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Time ;
    rdfs:range xsd:float ;
    rdfs:label "beat within bar" ;
    rdfs:comment "The beat number within the bar, from 0 to time:beatsPerBar." .

time:bar
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Time ;
    rdfs:range xsd:long ;
    rdfs:label "bar" ;
    rdfs:comment "A musical bar or measure." .

time:beat
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Time ;
    rdfs:range xsd:double ;
    rdfs:label "beat" ;
    rdfs:comment "The global running beat number." .

time:beatUnit
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Rate ;
    rdfs:range xsd:nonNegativeInteger ;
    rdfs:label "beat unit" ;
    rdfs:comment "The note value that counts as one beat." .

time:beatsPerBar
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Rate ;
    rdfs:range xsd:float ;
    rdfs:label "beats per bar" ;
    rdfs:comment "The number of beats in one bar." .

time:beatsPerMinute
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Rate ;
    rdfs:range xsd:float ;
    rdfs:label "beats per minute" ;
    rdfs:comment "Tempo in beats per minute." .

time:frame
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Time ;
    rdfs:range xsd:long ;
    rdfs:label "frame" ;
    rdfs:comment "A time stamp in audio frames." .

time:framesPerSecond
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Rate ;
    rdfs:range xsd:float ;
    rdfs:label "frames per second" ;
    rdfs:comment "Frame rate in frames per second." .

time:speed
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain time:Rate ;
    rdfs:range xsd:float ;
    rdfs:label "speed" ;
    rdfs:comment "The rate of the progress of time as a fraction of normal speed." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"units",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/extensions/units>
    a lv2:Specification ;
    lv2:minorVersion 5 ;
    lv2:microVersion 12 ;
    rdfs:seeAlso <units.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"units.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix units: <http://lv2plug.in/ns/extensions/units#> .

<http://lv2plug.in/ns/extensions/units>
    a doap:Project ;
    doap:name "LV2 Units" ;
    doap:shortdesc "Units for LV2 values." ;
    doap:created "2007-02-06" ;
    doap:homepage <http://lv2plug.in/ns/extensions/units> ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:release [
        doap:revision "5.12" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix outdated port description in documentation."
            ] , [
                rdfs:label "Remove overly restrictive domain from units:unit."
            ]
        ]
    ] , [
        doap:revision "5.10" ;
        doap:created "2015-04-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.12.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix non-existent port type in examples."
            ] , [
                rdfs:label "Add lv2:Parameter to domain of units:unit."
            ]
        ]
    ] , [
        doap:revision "5.8" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Remove units:name in favour of rdfs:label."
            ] , [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "5.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add unit for audio frames."
            ] , [
                rdfs:label "Add header of URI defines."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "5.4" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-units-5.4.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Make units.ttl a valid OWL 2 DL ontology."
            ] , [
                rdfs:label "Define used but undefined resources (units:name, units:render, units:symbol, units:Conversion, units:conversion, units:prefixConversion, units:to, and units:factor)."
            ] , [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "5.2" ;
        doap:created "2010-10-05" ;
        doap:file-release <http://lv2plug.in/spec/lv2-units-5.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system (for installation)."
            ] , [
                rdfs:label "Convert documentation to HTML and use lv2:documentation."
            ]
        ]
    ] , [
        doap:revision "5.0" ;
        doap:created "2010-10-05" ;
        doap:file-release <http://lv2plug.in/spec/lv2-units-5.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ] , [
                rdfs:label "Define used but undefined resources (units:name, units:render, units:symbol, units:Conversion, units:conversion, units:prefixConversion, units:to, and units:factor)."
            ] , [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] ;
    doap:developer <http://plugin.org.uk/swh.xrdf#me> ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    lv2:documentation """

This is a vocabulary for units typically used for control values in audio
processing.

For example, to say that a gain control is in decibels:

    :::turtle
    @prefix units: <http://lv2plug.in/ns/extensions/units#> .
    @prefix eg:    <http://example.org/> .

    eg:plugin lv2:port [
        a            lv2:ControlPort , lv2:InputPort ;
        lv2:index    0 ;
        lv2:symbol   "gain" ;
        lv2:name     "Gain" ;
        units:unit   units:db
    ] .

Using the same form, plugins may also specify one-off units inline, to give
better display hints to hosts:

    :::turtle
    eg:plugin lv2:port [
        a            lv2:ControlPort , lv2:InputPort ;
        lv2:index    0 ;
        lv2:symbol   "frob" ;
        lv2:name     "frob level" ;
        units:unit [
            a            units:Unit ;
            rdfs:label   "frobnication" ;
            units:symbol "fr" ;
            units:render "%f f"
        ]
    ] .

It is also possible to define conversions between various units, which makes it
possible for hosts to automatically convert between units where possible.  The
units defined in this extension include conversion definitions where it makes
sense to do so.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"units.ttl",
R"lv2ttl(@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix units: <http://lv2plug.in/ns/extensions/units#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/extensions/units>
    a owl:Ontology ;
    rdfs:label "LV2 Units" ;
    rdfs:comment "Units for LV2 values." ;
    rdfs:seeAlso <units.h> ,
        <units.meta.ttl> .

units:Unit
    a rdfs:Class ,
        owl:Class ;
    rdfs:label "Unit" ;
    rdfs:comment "A unit for a control value." .

units:unit
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:range units:Unit ;
    rdfs:label "unit" ;
    rdfs:comment "The unit used by the value of a port or parameter." .

units:render
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "unit format string" ;
    rdfs:domain units:Unit ;
    rdfs:range xsd:string ;
    rdfs:comment """A printf format string for rendering a value (e.g., "%f dB").""" .

units:symbol
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "unit symbol" ;
    rdfs:domain units:Unit ;
    rdfs:range xsd:string ;
    rdfs:comment """The abbreviated symbol for this unit (e.g., "dB").""" .

units:Conversion
    a rdfs:Class ,
        owl:Class ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty units:to ;
        owl:cardinality 1 ;
        rdfs:comment "A conversion MUST have exactly 1 units:to property."
    ] ;
    rdfs:label "Conversion" ;
    rdfs:comment "A conversion from one unit to another." .

units:conversion
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain units:Unit ;
    rdfs:range units:Conversion ;
    rdfs:label "conversion" ;
    rdfs:comment "A conversion from this unit to another." .

units:prefixConversion
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:subPropertyOf units:conversion ;
    rdfs:domain units:Unit ;
    rdfs:range units:Conversion ;
    rdfs:label "prefix conversion" ;
    rdfs:comment "A conversion from this unit to another with the same base but a different prefix." .

units:to
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain units:Conversion ;
    rdfs:range units:Unit ;
    rdfs:label "conversion target" ;
    rdfs:comment "The target unit this conversion converts to." .

units:factor
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:domain units:Conversion ;
    rdfs:label "conversion factor" ;
    rdfs:comment "The factor to multiply the source value by in order to convert to the target unit." .

units:s
    a units:Unit ;
    units:conversion [
        units:factor 0.0166666666 ;
        units:to units:min
    ] ;
    rdfs:label "seconds" ;
    rdfs:comment "Seconds, the SI base unit for time." ;
    units:prefixConversion [
        units:factor 1000 ;
        units:to units:ms
    ] ;
    units:render "%f s" ;
    units:symbol "s" .

units:ms
    a units:Unit ;
    rdfs:label "milliseconds" ;
    rdfs:comment "Milliseconds (thousandths of seconds)." ;
    units:prefixConversion [
        units:factor 0.001 ;
        units:to units:s
    ] ;
    units:render "%f ms" ;
    units:symbol "ms" .

units:min
    a units:Unit ;
    units:conversion [
        units:factor 60.0 ;
        units:to units:s
    ] ;
    rdfs:label "minutes" ;
    rdfs:comment "Minutes (60s of seconds and 60ths of an hour)." ;
    units:render "%f mins" ;
    units:symbol "min" .

units:bar
    a units:Unit ;
    rdfs:label "bars" ;
    rdfs:comment "Musical bars or measures." ;
    units:render "%f bars" ;
    units:symbol "bars" .

units:beat
    a units:Unit ;
    rdfs:label "beats" ;
    rdfs:comment "Musical beats." ;
    units:render "%f beats" ;
    units:symbol "beats" .

units:frame
    a units:Unit ;
    rdfs:label "audio frames" ;
    rdfs:comment "Audio frames or samples." ;
    units:render "%f frames" ;
    units:symbol "frames" .

units:m
    a units:Unit ;
    units:conversion [
        units:factor 39.37 ;
        units:to units:inch
    ] ;
    rdfs:label "metres" ;
    rdfs:comment "Metres, the SI base unit for length." ;
    units:prefixConversion [
        units:factor 100 ;
        units:to units:cm
    ] , [
        units:factor 1000 ;
        units:to units:mm
    ] , [
        units:factor 0.001 ;
        units:to units:km
    ] ;
    units:render "%f m" ;
    units:symbol "m" .

units:cm
    a units:Unit ;
    units:conversion [
        units:factor 0.3937 ;
        units:to units:inch
    ] ;
    rdfs:label "centimetres" ;
    rdfs:comment "Centimetres (hundredths of metres)." ;
    units:prefixConversion [
        units:factor 0.01 ;
        units:to units:m
    ] , [
        units:factor 10 ;
        units:to units:mm
    ] , [
        units:factor 0.00001 ;
        units:to units:km
    ] ;
    units:render "%f cm" ;
    units:symbol "cm" .

units:mm
    a units:Unit ;
    units:conversion [
        units:factor 0.03937 ;
        units:to units:inch
    ] ;
    rdfs:label "millimetres" ;
    rdfs:comment "Millimetres (thousandths of metres)." ;
    units:prefixConversion [
        units:factor 0.001 ;
        units:to units:m
    ] , [
        units:factor 0.1 ;
        units:to units:cm
    ] , [
        units:factor 0.000001 ;
        units:to units:km
    ] ;
    units:render "%f mm" ;
    units:symbol "mm" .

units:km
    a units:Unit ;
    units:conversion [
        units:factor 0.62138818 ;
        units:to units:mile
    ] ;
    rdfs:label "kilometres" ;
    rdfs:comment "Kilometres (thousands of metres)." ;
    units:prefixConversion [
        units:factor 1000 ;
        units:to units:m
    ] , [
        units:factor 100000 ;
        units:to units:cm
    ] , [
        units:factor 1000000 ;
        units:to units:mm
    ] ;
    units:render "%f km" ;
    units:symbol "km" .

units:inch
    a units:Unit ;
    units:conversion [
        units:factor 0.0254 ;
        units:to units:m
    ] ;
    rdfs:label "inches" ;
    rdfs:comment "An inch, defined as exactly 0.0254 metres." ;
    units:render "%f\"" ;
    units:symbol "in" .

units:mile
    a units:Unit ;
    units:conversion [
        units:factor 1609.344 ;
        units:to units:m
    ] ;
    rdfs:label "miles" ;
    rdfs:comment "A mile, defined as exactly 1609.344 metres." ;
    units:render "%f mi" ;
    units:symbol "mi" .

units:db
    a units:Unit ;
    rdfs:label "decibels" ;
    rdfs:comment "Decibels, a logarithmic relative unit where 0 is unity." ;
    units:render "%f dB" ;
    units:symbol "dB" .

units:pc
    a units:Unit ;
    units:conversion [
        units:factor 0.01 ;
        units:to units:coef
    ] ;
    rdfs:label "percent" ;
    rdfs:comment "Percentage, a ratio as a fraction of 100." ;
    units:render "%f%%" ;
    units:symbol "%" .

units:coef
    a units:Unit ;
    units:conversion [
        units:factor 100 ;
        units:to units:pc
    ] ;
    rdfs:label "coefficient" ;
    rdfs:comment "A scale coefficient where 1 is unity, or 100 percent." ;
    units:render "* %f" ;
    units:symbol "" .

units:hz
    a units:Unit ;
    rdfs:label "hertz" ;
    rdfs:comment "Hertz, or inverse seconds, the SI derived unit for frequency." ;
    units:prefixConversion [
        units:factor 0.001 ;
        units:to units:khz
    ] , [
        units:factor 0.000001 ;
        units:to units:mhz
    ] ;
    units:render "%f Hz" ;
    units:symbol "Hz" .

units:khz
    a units:Unit ;
    rdfs:label "kilohertz" ;
    rdfs:comment "Kilohertz (thousands of Hertz)." ;
    units:prefixConversion [
        units:factor 1000 ;
        units:to units:hz
    ] , [
        units:factor 0.001 ;
        units:to units:mhz
    ] ;
    units:render "%f kHz" ;
    units:symbol "kHz" .

units:mhz
    a units:Unit ;
    rdfs:label "megahertz" ;
    rdfs:comment "Megahertz (millions of Hertz)." ;
    units:prefixConversion [
        units:factor 1000000 ;
        units:to units:hz
    ] , [
        units:factor 0.001 ;
        units:to units:khz
    ] ;
    units:render "%f MHz" ;
    units:symbol "MHz" .

units:bpm
    a units:Unit ;
    rdfs:label "beats per minute" ;
    rdfs:comment "Beats Per Minute (BPM), the standard unit for musical tempo." ;
    units:prefixConversion [
        units:factor 0.0166666666 ;
        units:to units:hz
    ] ;
    units:render "%f BPM" ;
    units:symbol "BPM" .

units:oct
    a units:Unit ;
    units:conversion [
        units:factor 12.0 ;
        units:to units:semitone12TET
    ] ;
    rdfs:label "octaves" ;
    rdfs:comment "Octaves, relative musical pitch where +1 octave doubles the frequency." ;
    units:render "%f octaves" ;
    units:symbol "oct" .

units:cent
    a units:Unit ;
    units:conversion [
        units:factor 0.01 ;
        units:to units:semitone12TET
    ] ;
    rdfs:label "cents" ;
    rdfs:comment "Cents (hundredths of semitones)." ;
    units:render "%f ct" ;
    units:symbol "ct" .

units:semitone12TET
    a units:Unit ;
    units:conversion [
        units:factor 0.083333333 ;
        units:to units:oct
    ] ;
    rdfs:label "semitones" ;
    rdfs:comment "A semiton)lv2ttl" R"lv2ttl(e in the 12-tone equal temperament scale." ;
    units:render "%f semi" ;
    units:symbol "semi" .

units:degree
    a units:Unit ;
    rdfs:label "degrees" ;
    rdfs:comment "An angle where 360 degrees is one full rotation." ;
    units:render "%f deg" ;
    units:symbol "deg" .

units:midiNote
    a units:Unit ;
    rdfs:label "MIDI note" ;
    rdfs:comment "A MIDI note number." ;
    units:render "MIDI note %d" ;
    units:symbol "note" .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"patch",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/patch>
    a lv2:Specification ;
    lv2:minorVersion 2 ;
    lv2:microVersion 8 ;
    rdfs:seeAlso <patch.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"patch.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix patch: <http://lv2plug.in/ns/ext/patch#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/patch>
    a doap:Project ;
    doap:created "2012-02-09" ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:name "LV2 Patch" ;
    doap:shortdesc "A protocol for accessing and manipulating properties." ;
    doap:release [
        doap:revision "2.8" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix incorrect type of patch:sequenceNumber."
            ]
        ]
    ] , [
        doap:revision "2.6" ;
        doap:created "2019-02-03" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.16.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add patch:accept property."
            ] , [
                rdfs:label "Add patch:context property."
            ]
        ]
    ] , [
        doap:revision "2.4" ;
        doap:created "2015-04-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.12.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Define patch:Get with no subject to implicitly apply to reciever.  This can be used by UIs to get an initial description of a plugin."
            ] , [
                rdfs:label "Add patch:Copy method."
            ]
        ]
    ] , [
        doap:revision "2.2" ;
        doap:created "2014-08-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.10.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add patch:sequenceNumber for associating replies with requests."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2013-01-10" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Make patch:Set a compact message for setting one property."
            ] , [
                rdfs:label "Add patch:readable and patch:writable for describing available properties."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This is a vocabulary for messages that access and manipulate properties.
It can be used as a dynamic control interface for plugins,
or anything else with a property-based model.

The key underlying concept here is to control things by manipulating arbitrary properties,
rather than by calling application-specific methods.
This allows implementations to understand what messages do
(at least in a mechanical sense),
which makes things like caching, proxying, or undo relatively straightforward to implement.
Note, however, that this is only conceptual:
there is no requirement to implement a general property store.
Typically, a plugin will understand a fixed set of properties that represent its parameters or other internal state, and ignore everything else.

This protocol is syntax-agnostic,
and [homoiconic](https://en.wikipedia.org/wiki/Homoiconicity)
in the sense that the messages use the same format as the data they manipulate.
In particular, messages can be serialised as a binary [Object](atom.html#Object) for realtime plugin control,
or as Turtle for saving to a file,
sending over a network,
printing for debugging purposes,
and so on.

This specification only defines a semantic protocol,
there is no corresponding API.
It can be used with the [Atom](atom.html) extension to control plugins which support message-based parameters as defined by the [Parameters](parameters.html) extension.

For example, if a plugin defines a `eg:volume` parameter, it can be controlled by the host by sending a patch:Set message to the plugin instance:

    :::turtle
    [
        a patch:Set ;
        patch:property eg:volume ;
        patch:value 11.0 ;
    ]

Similarly, the host could get the current value for this parameter by sending a patch:Get message:

    :::turtle
    [
        a patch:Get ;
        patch:property eg:volume ;
    ]

The plugin would then respond with the same patch:Set message as above.
In this case, the plugin instance is implicitly the patch:subject,
but a specific subject can also be given for deeper control.

"""^^lv2:Markdown .

patch:Copy
    lv2:documentation """

After this, the destination has the same description as the subject,
and the subject is unchanged.

It is an error if the subject does not exist,
or if the destination already exists.

Multiple subjects may be given if the destination is a container,
but the semantics of this case are application-defined.

"""^^lv2:Markdown .

patch:Get
    lv2:documentation """

If a patch:property is given,
then the receiver should respond with a patch:Set message that gives only that property.

Otherwise, it should respond with a [concise bounded description](http://www.w3.org/Submission/CBD/) in a patch:Put message,
that is, a description that recursively includes any blank node values.

If a patch:subject is given, then the response should have the same subject.
If no subject is given, then the receiver is implicitly the subject.

If a patch:request node or a patch:sequenceNumber is given,
then the response should be a patch:Response and have the same property.
If neither is given, then the receiver can respond with a simple patch:Put message.
For example:

    :::turtle
    []
        a patch:Get ;
        patch:subject eg:something .

Could result in:

    :::turtle
    []
        a patch:Put ;
        patch:subject eg:something ;
        patch:body [
            eg:name "Something" ;
            eg:ratio 1.6180339887 ;
        ] .

"""^^lv2:Markdown .

patch:Insert
    lv2:documentation """

If the subject does not exist, it is created.  If the subject does already
exist, it is added to.

This request only adds properties, it never removes them.  The user must take
care that multiple values are not set for properties which should only have
one.

"""^^lv2:Markdown .

patch:Message
    lv2:documentation """

This is an abstract base class for all patch messages.  Concrete messages are
either a patch:Request or a patch:Response.

"""^^lv2:Markdown .

patch:Move
    lv2:documentation """

After this, the destination has the description that the subject had, and the
subject no longer exists.

It is an error if the subject does not exist, or if the destination already
exists.

"""^^lv2:Markdown .

patch:Patch
    lv2:documentation """

This method always has at least one subject, and exactly one patch:add and
patch:remove property.  The value of patch:add and patch:remove are nodes which
have the properties to add or remove from the subject(s), respectively.  The
special value patch:wildcard may be used as the value of a remove property to
remove all properties with the given predicate.  For example:

    :::turtle
    []
        a patch:Patch ;
        patch:subject <something> ;
        patch:add [
            eg:name "New name" ;
            eg:age 42 ;
        ] ;
        patch:remove [
            eg:name "Old name" ;
            eg:age patch:wildcard ;  # Remove all old eg:age properties
        ] .

"""^^lv2:Markdown .

patch:Put
    lv2:documentation """

If the subject does not already exist, it is created.  If the subject does
already exist, the patch:body is considered an updated version of it, and the
previous version is replaced.

    :::turtle
    []
        a patch:Put ;
        patch:subject <something> ;
        patch:body [
            eg:name "New name" ;
            eg:age 42 ;
        ] .

"""^^lv2:Markdown .

patch:Request
    a rdfs:Class ;
    rdfs:label "Request" ;
    rdfs:subClassOf)lv2ttl" R"lv2ttl( patch:Message ;
    lv2:documentation """

A request may have a patch:subject property, which specifies the resource that
the request applies to.  The subject may be omitted in contexts where it is
implicit, for example if the recipient is the subject.

"""^^lv2:Markdown .

patch:Set
    lv2:documentation """

This is equivalent to a patch:Patch which removes _all_ pre-existing values for
the property before setting the new value.  For example:

    :::turtle
    []
        a patch:Set ;
        patch:subject <something> ;
        patch:property eg:name ;
        patch:value "New name" .

Which is equivalent to:

    :::turtle
    []
        a patch:Patch ;
        patch:subject <something> ;
        patch:add [
            eg:name "New name" ;
        ] ;
        patch:remove [
            eg:name patch:wildcard ;
        ] .

"""^^lv2:Markdown .

patch:body
    lv2:documentation """

The details of this property's value depend on the type of message it is a part
of.

"""^^lv2:Markdown .

patch:context
    lv2:documentation """

For example, a plugin may have a special context for ephemeral properties which
are only relevant during the lifetime of the instance and should not be saved
in state.

The specific uses for contexts are application specific.  However, the context
MUST be a URI, and can be interpreted as the ID of a data model where
properties should be stored.  Implementations MAY have special support for
contexts, for example by storing in a quad store or serializing to a format
that supports multiple RDF graphs such as TriG.

"""^^lv2:Markdown .

patch:readable
    lv2:documentation """

See the similar patch:writable property for details.

"""^^lv2:Markdown .

patch:request
    lv2:documentation """

This can be used if referring directly to the URI or blank node ID of the
request is possible.  Otherwise, use patch:sequenceNumber.

"""^^lv2:Markdown .

patch:sequenceNumber
    lv2:documentation """

This property is used to associate replies with requests when it is not
feasible to refer to request URIs with patch:request.  A patch:Response with a
given sequence number is the reply to the previously send patch:Request with
the same sequence number.

The special sequence number 0 means that no reply is desired.

"""^^lv2:Markdown .

patch:wildcard
    lv2:documentation """

This makes it possible to describe the removal of all values for a given
property.

"""^^lv2:Markdown .

patch:writable
    lv2:documentation """

This is used to list properties that can be changed, for example to allow user
interfaces to present appropriate controls.  For example:

    :::turtle
    @prefix eg:   <http://example.org/> .
    @prefix rdf:  <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
    @prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
    @prefix xsd:  <http://www.w3.org/2001/XMLSchema#> .

    eg:title
        a rdf:Property ;
        rdfs:label "title" ;
        rdfs:range xsd:string .

    eg:plugin
        patch:writable eg:title .

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"patch.ttl",
R"lv2ttl(@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix patch: <http://lv2plug.in/ns/ext/patch#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/patch>
    a owl:Ontology ;
    rdfs:seeAlso <patch.h> ,
        <patch.meta.ttl> ;
    rdfs:label "LV2 Patch" ;
    rdfs:comment "A protocol for accessing and manipulating properties." .

patch:Ack
    a rdfs:Class ;
    rdfs:subClassOf patch:Response ;
    rdfs:label "Ack" ;
    rdfs:comment "An acknowledgement that a request was successful." .

patch:Copy
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ;
    rdfs:label "Copy" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:minCardinality 1 ;
        owl:onProperty patch:subject
    ] , [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:destination
    ] ;
    rdfs:comment "A request to copy the patch:subject to the patch:destination." .

patch:Delete
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ;
    rdfs:label "Delete" ;
    rdfs:comment "Request that the patch:subject or subjects be deleted." .

patch:Error
    a rdfs:Class ;
    rdfs:subClassOf patch:Response ;
    rdfs:label "Error" ;
    rdfs:comment "A response indicating an error processing a request." .

patch:Get
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ;
    rdfs:label "Get" ;
    rdfs:comment "A request for a description of the patch:subject." .

patch:Insert
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ;
    rdfs:label "Insert" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:subject
    ] ;
    rdfs:comment "A request to insert a patch:body into the patch:subject." .

patch:Message
    a rdfs:Class ;
    rdfs:label "Patch Message" ;
    rdfs:comment "A patch message." .

patch:Move
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ;
    rdfs:label "Move" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:subject
    ] , [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:destination
    ] ;
    rdfs:comment "A request to move the patch:subject to the patch:destination." .

patch:Patch
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ,
    [
        a owl:Restriction ;
        owl:minCardinality 1 ;
        owl:onProperty patch:subject
    ] , [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:add
    ] , [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:remove
    ] ;
    rdfs:label "Patch" ;
    rdfs:comment "A request to add and/or remove properties of the patch:subject." .

patch:Put
    a rdfs:Class ;
    rdfs:subClassOf patch:Request ;
    rdfs:label "Put" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:subject
    ] ;
    rdfs:comment "A request to put the patch:body as the patch:subject." .

patch:Request
    a rdfs:Class ;
    rdfs:label "Request" ;
    rdfs:subClassOf patch:Message ;
    rdfs:comment "A patch request message." .

patch:Response
    a rdfs:Class ;
    rdfs:subClassOf patch:Message ;
    rdfs:label "Response" ;
    rdfs:comment "A response to a patch:Request." .

patch:Set
    a rdfs:Class ;
    rdfs:label "Set" ;
    rdfs:subClassOf patch:Request ,
    [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:property
    ] , [
        a owl:Restriction ;
        owl:cardinality 1 ;
        owl:onProperty patch:value
    ] ;
    rdfs:comment "A compact request to set a property to a value." .

patch:accept
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "accept" ;
    rdfs:domain patch:Request ;
    rdfs:range rdfs:Class ;
    rdfs:comment "An accepted type for a response." .

patch:add
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain patch:Patch ;
    rdfs:range rdfs:Resource ;
    rdfs:label "add" ;
    rdfs:comment "The properties to add to the subject." .

patch:body
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain patch:Message ;
    rdfs:label "body" ;
    rdfs:comment "The body of a message." .

patch:context
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain patch:Message ;
    rdfs:label "context" ;
    rdfs:comment "The context of properties in this message." .

patch:destination
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain patch:Message ;
    rdfs:label "destination" ;
    rdfs:comment "The destination to move the patch:subject to." .

patch:property
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "property" ;
    rdfs:domain patch:Message ;
    rdfs:range rdf:Property ;
    rdfs:comment "The property for a patch:Set or patch:Get message." .

patch:readable
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "readable" ;
    rdfs:range rdf:Property ;
    rdfs:comment "A property that can be read with a patch:Get message." .

patch:remove
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:label "remove" ;
    rdfs:domain patch:Patch ;
    rdfs:range rdfs:Resource ;
    rdfs:comment "The properties to remove from the subject." .

patch:request
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:label "request" ;
    rdfs:domain patch:Response ;
    rdfs:range patch:Request ;
    rdfs:comment "The request this is a response to." .

patch:sequenceNumber
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:label "sequence number" ;
    rdfs:domain patch:Message ;
    rdfs:range xsd:int ;
    rdfs:comment "The sequence number of a request or response." .

patch:subject
    a rdf:Property ,
        owl:ObjectProperty ,
        owl:FunctionalProperty ;
    rdfs:domain patch:Message ;
    rdfs:label "subject" ;
    rdfs:comment "The subject this message applies to." .

patch:value
    a rdf:Property ,
        owl:DatatypeProperty ;
    rdfs:label "value" ;
    rdfs:domain patch:Set ;
    rdfs:range rdf:Property ;
    rdfs:comment "The value of a property in a patch:Set message." .

patch:wildcard
    a rdfs:Resource ;
    rdfs:label "wildcard" ;
    rdfs:comment "A wildcard that matches any resource." .

patch:writable
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:label "writable" ;
    rdfs:range rdf:Property ;
    rdfs:comment "A property that can be set with a patch:Set or patch:Patch message." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"parameters",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/parameters>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 4 ;
    rdfs:seeAlso <parameters.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"parameters.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix param: <http://lv2plug.in/ns/ext/parameters#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/parameters>
    a doap:Project ;
    doap:name "LV2 Parameters" ;
    doap:release [
        doap:revision "1.4" ;
        doap:created "2015-04-07" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.12.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add range to parameters so hosts know how to control them."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ] , [
                rdfs:label "Add param:sampleRate."
            ] , [
                rdfs:label "Add parameters.h of URI defines for convenience."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    doap:created "2009-00-00" ;
    doap:shortdesc "Common parameters for audio processing." ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:developer <http://lv2plug.in/ns/meta#larsl> ;
    lv2:documentation """

This is a vocabulary for parameters that are common in audio processing
software.  A <q>parameter</q> is purely a metadata concept, unrelated to any
particular code mechanism.  Parameters are used to assign meaning to controls
(for example, using lv2:designation for ports) so they can be used more
intelligently or presented to the user more efficiently.

"""^^lv2:Markdown .

param:wetDryRatio
    a lv2:Parameter ;
    rdfs:label "wet/dry ratio" ;
    lv2:documentation """

The ratio between processed and bypass components in output signal.  The dry
and wet percentages can be calculated from the following equations:

    :::c
    dry = (wetDryRatio.maximum - wetDryRatio.value) / wetDryRatio.maximum
    wet = wetDryRatio.value / wetDryRatio.maximum

Typically, maximum value of 1 or 100 and minimum value of 0 should be used.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"parameters.ttl",
R"lv2ttl(@prefix atom: <http://lv2plug.in/ns/ext/atom#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix param: <http://lv2plug.in/ns/ext/parameters#> .
@prefix pg: <http://lv2plug.in/ns/ext/port-groups#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix units: <http://lv2plug.in/ns/extensions/units#> .

<http://lv2plug.in/ns/ext/parameters>
    a owl:Ontology ;
    rdfs:label "LV2 Parameters" ;
    rdfs:comment "Common parameters for audio processing." ;
    rdfs:seeAlso <parameters.meta.ttl> .

param:ControlGroup
    a rdfs:Class ;
    rdfs:subClassOf pg:Group ;
    rdfs:label "Control Group" ;
    rdfs:comment "A group representing a set of associated controls." .

param:amplitude
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "amplitude" ;
    rdfs:comment "An amplitude as a factor, where 0 is silent and 1 is unity." .

param:attack
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "attack" ;
    rdfs:comment "The duration of an envelope attack stage." .

param:cutoffFrequency
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "cutoff frequency" ;
    rdfs:comment "The cutoff frequency, typically in Hz, for a filter." .

param:decay
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "decay" ;
    rdfs:comment "The duration of an envelope decay stage." .

param:delay
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "delay" ;
    rdfs:comment "The duration of an envelope delay stage." .

param:frequency
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "frequency" ;
    rdfs:comment "A frequency, typically in Hz." .

param:hold
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "hold" ;
    rdfs:comment "The duration of an envelope hold stage." .

param:pulseWidth
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "pulse width" ;
    rdfs:comment "The width of a pulse of a rectangular waveform." .

param:ratio
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "ratio" ;
    rdfs:comment "Compression ratio." .

param:release
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "release" ;
    rdfs:comment "The duration of an envelope release stage." .

param:resonance
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "resonance" ;
    rdfs:comment "The resonance of a filter." .

param:sustain
    a lv2:Parameter ;
    rdfs:label "sustain" ;
    rdfs:range atom:Float ;
    rdfs:comment "The level of an envelope sustain stage as a factor." .

param:threshold
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "threshold" ;
    rdfs:comment "Compression threshold." .

param:waveform
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    rdfs:label "waveform" ;
    rdfs:comment """The waveform "fader" for oscillators or modulators that have several.""" .

param:gain
    a lv2:Parameter ;
    rdfs:range atom:Float ;
    lv2:default 0.0 ;
    lv2:minimum -20.0 ;
    lv2:maximum 20.0 ;
    units:unit units:db ;
    rdfs:label "gain" ;
    rdfs:comment "Gain in decibels." .

param:wetDryRatio
    a lv2:Parameter ;
    rdfs:label "wet/dry ratio" ;
    rdfs:comment "The ratio between processed and bypassed levels in the output." .

param:wetLevel
    a lv2:Parameter ;
    rdfs:label "wet level" ;
    rdfs:comment "The level of the processed component of a signal." .

param:dryLevel
    a lv2:Parameter ;
    rdfs:label "dry level" ;
    rdfs:comment "The level of the unprocessed component of a signal." .

param:bypass
    a lv2:Parameter ;
    rdfs:label "bypass" ;
    rdfs:comment "A boolean parameter that disables processing if true." .

param:sampleRate
    a lv2:Parameter ;
    rdfs:label "sample rate" ;
    rdfs:comment "A sample rate in Hz." .

param:EnvelopeControls
    a rdfs:Class ;
    rdfs:subClassOf param:ControlGroup ;
    rdfs:label "Envelope Controls" ;
    rdfs:comment "Typical controls for a DAHDSR envelope." ;
    pg:element [
        lv2:index 0 ;
        lv2:designation param:delay
    ] , [
        lv2:index 1 ;
        lv2:designation param:attack
    ] , [
        lv2:index 2 ;
        lv2:designation param:hold
    ] , [
        lv2:index 3 ;
        lv2:designation param:decay
    ] , [
        lv2:index 4 ;
        lv2:designation param:sustain
    ] , [
        lv2:index 5 ;
        lv2:designation param:release
    ] .

param:OscillatorControls
    a rdfs:Class ;
    rdfs:subClassOf param:ControlGroup ;
    rdfs:label "Oscillator Controls" ;
    rdfs:comment "Typical controls for an oscillator." ;
    pg:element [
        lv2:designation param:frequency
    ] , [
        lv2:designation param:amplitude
    ] , [
        lv2:designation param:waveform
    ] , [
        lv2:designation param:pulseWidth
    ] .

param:FilterControls
    a rdfs:Class ;
    rdfs:subClassOf param:ControlGroup ;
    rdfs:label "Filter Controls" ;
    rdfs:comment "Typical controls for a filter." ;
    pg:element [
        lv2:designation param:cutoffFrequency
    ] , [
        lv2:designation param:resonance
    ] .

param:CompressorControls
    a rdfs:Class ;
    rdfs:subClassOf param:ControlGroup ;
    rdfs:label "Compressor Controls" ;
    rdfs:comment "Typical controls for a compressor." ;
    pg:element [
        lv2:designation param:threshold
    ] , [
        lv2:designation param:ratio
    ] .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"urid",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/urid>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 4 ;
    rdfs:seeAlso <urid.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"urid.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix urid: <http://lv2plug.in/ns/ext/urid#> .

<http://lv2plug.in/ns/ext/urid>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 URID" ;
    doap:shortdesc "Features for mapping URIs to and from integers." ;
    doap:created "2011-07-22" ;
    doap:developer <http://lv2plug.in/ns/meta#gabrbedd> ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.4" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix typo in urid:unmap documentation."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add feature struct names."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-urid-1.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a simple mechanism for plugins to map URIs to and from
integers.  This is usually used for performance reasons, for example for
processing events with URI types in real-time audio code).  Typically, plugins
map URIs to integers for things they "understand" at instantiation time, and
store those values for use in the audio thread without doing any string
comparison.  This allows for the extensibility of RDF but with the performance
of integers.

This extension is intended as an improved and simplified replacement for the
[uri-map](uri-map.html) extension, since the `map` context parameter there has
proven problematic.  This extension is functionally equivalent to the uri-map
extension with a NULL context.  New implementations are encouraged to use this
extension for URI mapping.

"""^^lv2:Markdown .

urid:map
    lv2:documentation """

To support this feature, the host must pass an LV2_Feature to
LV2_Descriptor::instantiate() with URI LV2_URID__map and data pointed to an
instance of LV2_URID_Map.

"""^^lv2:Markdown .

urid:unmap
    lv2:documentation """

To support this feature, the host must pass an LV2_Feature to
LV2_Descriptor::instantiate() with URI LV2_URID__unmap and data pointed to an
instance of LV2_URID_Unmap.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"urid.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix urid: <http://lv2plug.in/ns/ext/urid#> .

<http://lv2plug.in/ns/ext/urid>
    a owl:Ontology ;
    rdfs:label "LV2 URID" ;
    rdfs:comment "Features for mapping URIs to and from integers." ;
    rdfs:seeAlso <urid.h> ,
        <urid.meta.ttl> .

urid:map
    a lv2:Feature ;
    rdfs:label "map" ;
    rdfs:comment "A feature to map URI strings to integer URIDs." .

urid:unmap
    a lv2:Feature ;
    rdfs:label "unmap" ;
    rdfs:comment "A feature to unmap URIDs back to strings." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"uri-map",
{
juce::lv2::BundleResource
{
"uri-map.meta.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/uri-map>
    a doap:Project ;
    doap:maintainer <http://drobilla.net/drobilla#me> ;
    doap:created "2008-00-00" ;
    doap:developer <http://lv2plug.in/ns/meta#larsl> ,
        <http://drobilla.net/drobilla#me> ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 URI Map" ;
    doap:shortdesc "A feature for mapping URIs to integers." ;
    doap:release [
        doap:revision "1.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2011-11-21" ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Deprecate uri-map in favour of urid."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2011-05-26" ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system (for installation)."
            ] , [
                rdfs:label "Mark up documentation in HTML using lv2:documentation."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2010-10-18" ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

<span class="warning">This extension is deprecated.</span> New implementations
should use [LV2 URID](urid.html) instead.

This extension defines a simple mechanism for plugins to map URIs to integers,
usually for performance reasons (e.g. processing events typed by URIs in real
time).  The expected use case is for plugins to map URIs to integers for things
they 'understand' at instantiation time, and store those values for use in the
audio thread without doing any string comparison.  This allows the
extensibility of RDF with the performance of integers (or centrally defined
enumerations).

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/uri-map>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 6 ;
    rdfs:seeAlso <uri-map.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"uri-map.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix umap: <http://lv2plug.in/ns/ext/uri-map#> .

<http://lv2plug.in/ns/ext/uri-map>
    a lv2:Feature ;
    owl:deprecated true ;
    rdfs:label "LV2 URI Map" ;
    rdfs:comment "A feature for mapping URIs to integers." ;
    rdfs:seeAlso <uri-map.h> ,
        <uri-map.meta.ttl> .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"log",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/log>
    a lv2:Specification ;
    lv2:minorVersion 2 ;
    lv2:microVersion 4 ;
    rdfs:seeAlso <log.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"log.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix log: <http://lv2plug.in/ns/ext/log#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/log>
    a doap:Project ;
    doap:name "LV2 Log" ;
    doap:shortdesc "A feature for writing log messages." ;
    doap:created "2012-01-12" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "2.4" ;
        doap:created "2016-07-30" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.14.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add lv2_log_logger_set_map() for changing the URI map of an existing logger."
            ]
        ]
    ] , [
        doap:revision "2.2" ;
        doap:created "2014-01-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.8.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add missing include string.h to logger.h for memset."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2013-01-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add logger convenience API."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a feature, log:log, which allows plugins to print log
messages with an API similar to the standard C `printf` function.  This allows,
for example, plugin logs to be nicely presented to the user in a graphical user
interface.

Different log levels are defined by URI and passed as an LV2_URID.  This
extensions defines standard levels which are expected to be understood by all
implementations and should be sufficient in most cases, but advanced
implementations may define and use additional levels to suit their needs.

"""^^lv2:Markdown .

log:Entry
    a rdfs:Class ;
    rdfs:label "Log Entry" ;
    lv2:documentation """

Subclasses of this are passed as the `type` parameter to LV2_Log_Log methods to
describe the nature of the log entry.

"""^^lv2:Markdown .

log:Error
    lv2:documentation """

An error should only be posted when a serious unexpected error occurs, and
should be actively shown to the user by the host.

"""^^lv2:Markdown .

log:Note
    lv2:documentation """

A note records some useful piece of information, but may be ignored.  The host
should provide passive access to note entries to the user.

"""^^lv2:Markdown .

log:Warning
    lv2:documentation """

A warning should be posted when an unexpected, but non-critical, error occurs.
The host should provide passive access to warnings entries to the user, but may
also choose to actively show them.

"""^^lv2:Markdown .

log:Trace
    lv2:documentation """

A trace should not be displayed during normal operation, but the host may
implement an option to display them for debugging purposes.

This entry type is special in that one may be posted in a real-time thread.  It
is assumed that if debug tracing is enabled, real-time performance is not a
concern.  However, the host MUST guarantee that posting a trace _is_ real-time
safe if debug tracing is not enabled (for example, by simply ignoring the call
as early as possible).

"""^^lv2:Markdown .

log:log
    lv2:documentation """

A feature which plugins may use to log messages.  To support this feature,
the host must pass an LV2_Feature to LV2_Descriptor::instantiate() with URI
LV2_LOG__log and data pointed to an instance of LV2_Log_Log.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"log.ttl",
R"lv2ttl(@prefix log: <http://lv2plug.in/ns/ext/log#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/log>
    a owl:Ontology ;
    rdfs:label "LV2 Log" ;
    rdfs:comment "A feature for writing log messages." ;
    rdfs:seeAlso <log.h> ,
        <log.meta.ttl> .

log:Entry
    a rdfs:Class ;
    rdfs:label "Entry" ;
    rdfs:comment "A log entry." .

log:Error
    a rdfs:Class ;
    rdfs:label "Error" ;
    rdfs:subClassOf log:Entry ;
    rdfs:comment "An error message." .

log:Note
    a rdfs:Class ;
    rdfs:label "Note" ;
    rdfs:subClassOf log:Entry ;
    rdfs:comment "An informative message." .

log:Warning
    a rdfs:Class ;
    rdfs:label "Warning" ;
    rdfs:subClassOf log:Entry ;
    rdfs:comment "A warning message." .

log:Trace
    a rdfs:Class ;
    rdfs:label "Trace" ;
    rdfs:subClassOf log:Entry ;
    rdfs:comment "A debugging trace message." .

log:log
    a lv2:Feature ;
    rdfs:label "log" ;
    rdfs:comment "Logging feature." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"dynmanifest",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/dynmanifest>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 6 ;
    rdfs:seeAlso <dynmanifest.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"dynmanifest.ttl",
R"lv2ttl(@prefix dman: <http://lv2plug.in/ns/ext/dynmanifest#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/dynmanifest>
    a owl:Ontology ;
    rdfs:label "LV2 Dyn Manifest" ;
    rdfs:comment "Support for dynamic manifest data generation." ;
    rdfs:seeAlso <dynmanifest.h> ,
        <dynmanifest.meta.ttl> .

dman:DynManifest
    a rdfs:Class ;
    rdfs:label "Dynamic Manifest" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty lv2:binary ;
        owl:minCardinality 1 ;
        rdfs:comment "A DynManifest MUST have at least one lv2:binary."
    ] ;
    rdfs:comment "Dynamic manifest for an LV2 binary." .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"dynmanifest.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix dman: <http://lv2plug.in/ns/ext/dynmanifest#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/dynmanifest>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 Dynamic Manifest" ;
    doap:homepage <http://naspro.atheme.org> ;
    doap:created "2009-06-13" ;
    doap:shortdesc "Support for dynamic manifest data generation." ;
    doap:programming-language "C" ;
    doap:developer <http://lv2plug.in/ns/meta#daste> ;
    doap:release [
        doap:revision "1.6" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-dynmanifest-1.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2010-04-10" ;
        doap:file-release <http://lv2plug.in/spec/lv2-dyn-manifest-1.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

The LV2 API, on its own, cannot be used to write plugin libraries where data is
dynamically generated at runtime, since LV2 requires needed information to be
provided in one or more static data (RDF) files. This API addresses this
limitation by extending the LV2 API.

To detect that a plugin library implements a dynamic manifest generator, the
host checks its static manifest for a description like:

    :::turtle
    <http://example.org/my-dynamic-manifest>
        a dman:DynManifest ;
        lv2:binary <mydynmanifest.so> .

To load the data, the host loads the library (`mydynmanifest.so` in this
example) as usual and fetches the dynamic Turtle data from it using this API.

The host is allowed to request regeneration of the dynamic manifest multiple
times, and the plugin library is expected to provide updated data if/when
possible. All data and references provided via this API before the last
regeneration of the dynamic manifest is to be considered invalid by the host,
including plugin descriptors whose URIs were discovered using this API.

### Accessing Data

To access data using this API, the host must:

  1. Call lv2_dyn_manifest_open().

  2. Create a `FILE` for functions to write data to (for example with `tmpfile()`).

  3. Get a list of exposed subject URIs using lv2_dyn_manifest_get_subjects().

  4. Call lv2_dyn_manifest_get_data() for each URI of interest to write the
  related data to the file.

  5. Call lv2_dyn_manifest_close().

  6. Parse the content of the file(s).

  7. Remove the file(s).

Each call to the above mentioned dynamic manifest functions MUST write a
complete, valid Turtle document (including all needed prefix definitions) to
the output FILE.

Each call to lv2_dyn_manifest_open() causes the (re)generation of the dynamic
manifest data, and invalidates all data fetched before the call.

In case the plugin library uses this same API to access other dynamic
manifests, it MUST implement some mechanism to avoid potentially endless loops
(such as A loads B, B loads A, etc.) and, in case such a loop is detected, the
operation MUST fail.  For this purpose, use of a static boolean flag is
suggested.

### Threading Rules

All of the functions defined by this specification belong to the Discovery
class.


"""^^lv2:Markdown .

dman:DynManifest
    lv2:documentation """

There MUST NOT be any instances of dman:DynManifest in the generated manifest.

All relative URIs in the generated data MUST be relative to the base path that
would be used to parse a normal LV2 manifest (the bundle path).

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"worker",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/worker>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 2 ;
    rdfs:seeAlso <worker.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"worker.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix work: <http://lv2plug.in/ns/ext/worker#> .

<http://lv2plug.in/ns/ext/worker>
    a doap:Project ;
    doap:name "LV2 Worker" ;
    doap:shortdesc "Support for doing non-realtime work in plugins." ;
    doap:created "2012-03-22" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.2" ;
        doap:created "2020-04-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.18.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension allows plugins to schedule work that must be performed in
another thread.  Plugins can use this interface to safely perform work that is
not real-time safe, and receive the result in the run context.  The details of
threading are managed by the host, allowing plugins to be simple and portable
while using resources more efficiently.

This interface is designed to gracefully support single-threaded synchronous
execution, which allows the same code to work with sample accuracy for offline
rendering.  For example, a sampler plugin may schedule a sample to be loaded
from disk in another thread.  During live execution, the host will call the
plugin's work method from another thread, and deliver the result to the audio
thread when it is finished.  However, during offline export, the
<q>scheduled</q> load would be executed immediately in the same thread.  This
enables reproducible offline rendering, where any changes affect the output
immediately regardless of how long the work takes to execute.

"""^^lv2:Markdown .

work:interface
    lv2:documentation """

The work interface provided by a plugin, LV2_Worker_Interface.

    :::turtle

    @prefix work: <http://lv2plug.in/ns/ext/worker#> .

    <plugin>
        a lv2:Plugin ;
        lv2:extensionData work:interface .

"""^^lv2:Markdown .

work:schedule
    lv2:documentation """

The work scheduling feature provided by a host, LV2_Worker_Schedule.

If the host passes this feature to LV2_Descriptor::instantiate, the plugin MAY
use it to schedule work in the audio thread, and MUST NOT call it in any other
context.  Hosts MAY pass this feature to other functions as well, in which case
the plugin MAY use it to schedule work in the calling context.  The plugin MUST
NOT assume any relationship between different schedule features.

"""^^lv2:Markdown .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"worker.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix work: <http://lv2plug.in/ns/ext/worker#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/worker>
    a owl:Ontology ;
    rdfs:label "LV2 Worker" ;
    rdfs:comment "Support for doing non-realtime work in plugins." ;
    owl:imports <http://lv2plug.in/ns/lv2core> ;
    rdfs:seeAlso <worker.h> ,
        <worker.meta.ttl> .

work:interface
    a lv2:ExtensionData ;
    rdfs:label "work interface" ;
    rdfs:comment "The work interface provided by a plugin." .

work:schedule
    a lv2:Feature ;
    rdfs:label "work schedule" ;
    rdfs:comment "The work scheduling feature provided by a host." .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"presets",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/presets>
    a lv2:Specification ;
    lv2:minorVersion 2 ;
    lv2:microVersion 8 ;
    rdfs:seeAlso <presets.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"presets.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix pset: <http://lv2plug.in/ns/ext/presets#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

<http://lv2plug.in/ns/ext/presets>
    a owl:Ontology ;
    rdfs:label "LV2 Presets" ;
    rdfs:comment "Presets for LV2 plugins." ;
    rdfs:seeAlso <presets.meta.ttl> .

pset:Bank
    a rdfs:Class ;
    rdfs:label "Bank" ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty rdfs:label ;
        owl:someValuesFrom xsd:string ;
        rdfs:comment "A Bank MUST have at least one string rdfs:label."
    ] ;
    rdfs:comment "A bank of presets." .

pset:Preset
    a rdfs:Class ;
    rdfs:subClassOf lv2:PluginBase ;
    rdfs:label "Preset" ;
    rdfs:comment "A preset for an LV2 plugin." ;
    rdfs:subClassOf [
        a owl:Restriction ;
        owl:onProperty rdfs:label ;
        owl:someValuesFrom xsd:string ;
        rdfs:comment "A Preset MUST have at least one string rdfs:label."
    ] .

pset:bank
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain pset:Preset ;
    rdfs:range pset:Bank ;
    rdfs:label "bank" ;
    rdfs:comment "The bank this preset belongs to." .

pset:value
    a rdf:Property ,
        owl:DatatypeProperty ,
        owl:FunctionalProperty ;
    rdfs:domain lv2:PortBase ;
    rdfs:label "value" ;
    rdfs:comment "The value of a port in a preset." .

pset:preset
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain lv2:PluginBase ;
    rdfs:range pset:Preset ;
    rdfs:label "preset" ;
    rdfs:comment "The preset currently applied to a plugin instance." .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"presets.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix pset: <http://lv2plug.in/ns/ext/presets#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/presets>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 Presets" ;
    doap:shortdesc "Presets for LV2 plugins." ;
    doap:created "2009-00-00" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "2.8" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Use consistent label style."
            ] , [
                rdfs:label "Add preset banks."
            ]
        ]
    ] , [
        doap:revision "2.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add pset:preset property for describing the preset currently applied to a plugin instance."
            ] , [
                rdfs:label "Remove pset:appliesTo property, use lv2:appliesTo instead."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "2.2" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-presets-2.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "2.0" ;
        doap:created "2010-10-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-presets-2.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This is a vocabulary for LV2 plugin presets, that is, named sets of control
values and possibly other state.  The structure of a pset:Preset is
deliberately identical to that of an lv2:Plugin, and can be thought of as a
plugin template or overlay.

Presets may be defined in any bundle, including the plugin's bundle, separate
third party preset bundles, or user preset bundles saved by hosts.  Since
preset data tends to be large, it is recommended that plugins describe presets
in a separate file(s) to avoid slowing down hosts.  The `manifest.ttl` of a
bundle containing presets should list them like so:

    :::turtle
    eg:mypreset
        a             pset:Preset ;
        lv2:appliesTo eg:myplugin ;
        rdfs:seeAlso  <mypreset.ttl> .

"""^^lv2:Markdown .

pset:Preset
    lv2:documentation """

The structure of a Preset deliberately mirrors that of a plugin, so existing
predicates can be used to describe any data associated with the preset.  For
example:

    :::turtle
    @prefix eg: <http://example.org/> .

    eg:mypreset
        a pset:Preset ;
        rdfs:label "One louder" ;
        lv2:appliesTo eg:myplugin ;
        lv2:port [
            lv2:symbol "volume1" ;
            pset:value 11.0
        ] , [
            lv2:symbol "volume2" ;
            pset:value 11.0
        ] .

A Preset SHOULD have at least one lv2:appliesTo property.  Each Port on a
Preset MUST have at least a lv2:symbol property and a pset:value property.

Hosts SHOULD save user presets to a bundle in the user-local LV2 directory (for
example `~/.lv2`) with a name like `<Plugin_Name>_<Preset_Name>.preset.lv2`
(for example `LV2_Amp_At_Eleven.preset.lv2`), where names are transformed to be
valid LV2 symbols for maximum compatibility.

"""^^lv2:Markdown .

pset:value
    lv2:documentation """

This property is used in a similar way to lv2:default.

"""^^lv2:Markdown .

pset:preset
    lv2:documentation """

Specifies the preset currently applied to a plugin instance.  This property may
be useful for saving state, or notifying a plugin instance at run-time about a
preset change.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"event",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/event>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 12 ;
    rdfs:seeAlso <event.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"event.ttl",
R"lv2ttl(@prefix ev: <http://lv2plug.in/ns/ext/event#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix owl: <http://www.w3.org/2002/07/owl#> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/event>
    a owl:Ontology ;
    owl:deprecated true ;
    rdfs:label "LV2 Event" ;
    rdfs:comment "A port-based real-time generic event interface." ;
    rdfs:seeAlso <event.h> ,
        <event-helpers.h> ,
        <event.meta.ttl> .

ev:EventPort
    a rdfs:Class ;
    rdfs:label "Event Port" ;
    rdfs:subClassOf lv2:Port ;
    rdfs:comment "An LV2 event port." .

ev:Event
    a rdfs:Class ;
    rdfs:label "Event" ;
    rdfs:comment "A single generic time-stamped event." .

ev:TimeStamp
    a rdfs:Class ;
    rdfs:label "Event Time Stamp" ;
    rdfs:comment "The time stamp of an Event." .

ev:FrameStamp
    a rdfs:Class ;
    rdfs:subClassOf ev:TimeStamp ;
    rdfs:label "Audio Frame Time Stamp" ;
    rdfs:comment "The default time stamp unit for an event." .

ev:generic
    a lv2:PortProperty ;
    rdfs:label "generic event port" ;
    rdfs:comment "Port works with generic events." .

ev:supportsEvent
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ev:EventPort ;
    rdfs:range rdfs:Class ;
    rdfs:label "supports event type" ;
    rdfs:comment "An event type supported by this port." .

ev:inheritsEvent
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ev:EventPort ,
        lv2:OutputPort ;
    rdfs:range lv2:Port ;
    rdfs:label "inherits event type" ;
    rdfs:comment "Output port inherits event types from an input port." .

ev:supportsTimeStamp
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ev:EventPort ,
        lv2:InputPort ;
    rdfs:range rdfs:Class ;
    rdfs:label "supports time stamp type" ;
    rdfs:comment "A time stamp type suported by this input port." .

ev:generatesTimeStamp
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ev:EventPort ,
        lv2:OutputPort ;
    rdfs:range rdfs:Class ;
    rdfs:label "generates time stamp type" ;
    rdfs:comment "A time stamp type generated by this input port." .

ev:inheritsTimeStamp
    a rdf:Property ,
        owl:ObjectProperty ;
    rdfs:domain ev:EventPort ,
        lv2:OutputPort ;
    rdfs:range lv2:Port ;
    rdfs:label "inherits time stamp type" ;
    rdfs:comment "Output port inherits time stamp types from an input port." .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"event.meta.ttl",
R"lv2ttl(@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix ev: <http://lv2plug.in/ns/ext/event#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/event>
    a doap:Project ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 Event" ;
    doap:shortdesc "A port-based real-time generic event interface." ;
    doap:created "2008-00-00" ;
    doap:developer <http://drobilla.net/drobilla#me> ,
        <http://lv2plug.in/ns/meta#larsl> ;
    doap:release [
        doap:revision "1.12" ;
        doap:created "2014-08-08" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.10.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Minor documentation improvements."
            ]
        ]
    ] , [
        doap:revision "1.10" ;
        doap:created "2013-01-13" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.4.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix incorrect return type in lv2_event_get()."
            ]
        ]
    ] , [
        doap:revision "1.8" ;
        doap:created "2012-10-14" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.2.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Make event iterator gracefully handle optional ports."
            ] , [
                rdfs:label "Remove asserts from event-helper.h."
            ] , [
                rdfs:label "Use more precise domain and range for EventPort properties."
            ] , [
                rdfs:label "Use consistent label style."
            ]
        ]
    ] , [
        doap:revision "1.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Fix bug in lv2_event_reserve()."
            ] , [
                rdfs:label "Fix incorrect ranges of some properties."
            ] , [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-event-1.4.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Update packaging."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2011-05-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-event-1.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system (for installation)."
            ] , [
                rdfs:label "Convert documentation to HTML and use lv2:documentation."
            ] , [
                rdfs:label "Use lv2:Specification to be discovered as an extension."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2010-11-24" ;
        doap:file-release <http://lv2plug.in/spec/lv2-event-1.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

<span class="warning">This extension is deprecated.</span> New implementations
should use <a href="atom.html">LV2 Atom</a> instead.

This extension defines a generic time-stamped event port type, which can be
used to create plugins that read and write real-time events, such as MIDI,
OSC, or any other type of event payload.  The type(s) of event supported by
a port is defined in the data file for a plugin, for example:

    :::turtle
    <http://example.org/some-plugin>
        lv2:port [
            a ev:EventPort, lv2:InputPort ;
            lv2:index 0 ;
            ev:supportsEvent <http://lv2plug.in/ns/ext/midi#MidiEvent> ;
            lv2:symbol "midi_input" ;
            lv2:name "MIDI input" ;
        ] .

"""^^lv2:Markdown .

ev:EventPort
    lv2:documentation """

Ports of this type will be connected to a struct of type LV2_Event_Buffer,
defined in event.h.  These ports contain a sequence of generic events (possibly
several types mixed in a single stream), the specific types of which are
defined by some URI in another LV2 extension.

"""^^lv2:Markdown .

ev:Event
    a rdfs:Class ;
    rdfs:label "Event" ;
    lv2:documentation """

An ev:EventPort contains an LV2_Event_Buffer which contains a sequence of these
events.  The binary format of LV2 events is defined by the LV2_Event struct in
event.h.

Specific event types (such as MIDI or OSC) are defined by extensions, and
should be rdfs:subClassOf this class.

"""^^lv2:Markdown .

ev:TimeStamp
    lv2:documentation """

This defines the meaning of the 'frames' and 'subframes' fields of an LV2_Event
(both unsigned 32-bit integers).

"""^^lv2:Markdown .

ev:FrameStamp
    lv2:documentation """

The default time stamp unit for an LV2 event: the frames field represents audio
frames (in the sample rate passed to intantiate), and the subframes field is
1/UINT32_MAX of a frame.

"""^^lv2:Markdown .

ev:generic
    lv2:documentation """

Indicates that this port does something meaningful for any event type.  This is
useful for things like event mixers, delays, serialisers, and so on.

If this property is set, hosts should consider the port suitable for any type
of event.  Otherwise, hosts should consider the port 'appropriate' only for the
specific event types listed with :supportsEvent.  Note that plugins must
gracefully handle unknown event types whether or not this property is present.

"""^^lv2:Markdown .

ev:supportsEvent
    lv2:documentation """

Indicates that this port supports or "understands" a certain event type.

For input ports, this means the plugin understands and does something useful
with events of this type.  For output ports, this means the plugin may generate
events of this type.  If the plugin never actually generates events of this
type, but might pass them through from an input, this property should not be
set (use ev:inheritsEvent for that).

Plugins with event input ports must always gracefully handle any type of event,
even if it does not 'support' it.  This property should always be set for event
types the plugin understands/generates so hosts can discover plugins
appropriate for a given scenario (for example, plugins with a MIDI input).
Hosts are not expected to consider event ports suitable for some type of event
if the relevant :supportsEvent property is not set, unless the ev:generic
property for that port is also set.


"""^^lv2:Markdown .

ev:inheritsEvent
    lv2:documentation """

Indicates that this output port might pass through events that arrived at some
other input port (or generate an event of the same type as events arriving at
that input).  The host must always check the stamp type of all outputs when
connecting an input, but this property should be set whenever it applies.


"""^^lv2:Markdown .

ev:supportsTimeStamp
    lv2:documentation """

Indicates that this port supports or "understands" a certain time stamp type.
Meaningful only for input ports, the host must never connect a port to an event
buffer with a time stamp type that isn't supported by the port.

"""^^lv2:Markdown .

ev:generatesTimeStamp
    lv2:documentation """

Indicates that this port may output a certain time stamp type, regardless of
the time stamp type of any input ports.

If the port outputs stamps based on what type inputs are connected to, this
property should not be set (use the ev:inheritsTimeStamp property for that).
Hosts MUST check the time_stamp value of any output port buffers after a call
to connect_port on ANY event input port on the plugin.

If the plugin changes the stamp_type field of an output event buffer during a
call to run(), the plugin must call the stamp_type_changed function provided by
the host in the LV2_Event_Feature struct, if it is non-NULL.

"""^^lv2:Markdown .

ev:inheritsTimeStamp
    lv2:documentation """

Indicates that this port follows the time stamp type of an input port.

This property is not necessary, but it should be set for outputs that base
their output type on an input port so the host can make more sense of the
pl)lv2ttl" R"lv2ttl(ugin and provide a more sensible interface.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}
, juce::lv2::Bundle
{
"data-access",
{
juce::lv2::BundleResource
{
"manifest.ttl",
R"lv2ttl(@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/data-access>
    a lv2:Specification ;
    lv2:minorVersion 1 ;
    lv2:microVersion 6 ;
    rdfs:seeAlso <data-access.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"data-access.ttl",
R"lv2ttl(@prefix da: <http://lv2plug.in/ns/ext/data-access#> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/data-access>
    a lv2:Feature ;
    rdfs:label "data access" ;
    rdfs:comment "A feature that provides access to plugin extension data." ;
    rdfs:seeAlso <data-access.h> ,
        <data-access.meta.ttl> .

)lv2ttl"
}
, juce::lv2::BundleResource
{
"data-access.meta.ttl",
R"lv2ttl(@prefix da: <http://lv2plug.in/ns/ext/data-access#> .
@prefix dcs: <http://ontologi.es/doap-changeset#> .
@prefix doap: <http://usefulinc.com/ns/doap#> .
@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix lv2: <http://lv2plug.in/ns/lv2core#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .

<http://lv2plug.in/ns/ext/data-access>
    a doap:Project ;
    rdfs:seeAlso <data-access.h> ;
    doap:license <http://opensource.org/licenses/isc> ;
    doap:name "LV2 Data Access" ;
    doap:shortdesc "Provides access to plugin extension data." ;
    doap:created "2008-00-00" ;
    doap:developer <http://drobilla.net/drobilla#me> ;
    doap:release [
        doap:revision "1.6" ;
        doap:created "2012-04-17" ;
        doap:file-release <http://lv2plug.in/spec/lv2-1.0.0.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Merge with unified LV2 package."
            ]
        ]
    ] , [
        doap:revision "1.4" ;
        doap:created "2011-11-21" ;
        doap:file-release <http://lv2plug.in/spec/lv2-data-access-1.4.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Update packaging."
            ] , [
                rdfs:label "Improve documentation."
            ]
        ]
    ] , [
        doap:revision "1.2" ;
        doap:created "2011-05-26" ;
        doap:file-release <http://lv2plug.in/spec/lv2-data-access-1.2.tar.bz2> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Add build system for installation."
            ] , [
                rdfs:label "Switch to ISC license."
            ]
        ]
    ] , [
        doap:revision "1.0" ;
        doap:created "2010-10-04" ;
        doap:file-release <http://lv2plug.in/spec/lv2-data-access-1.0.tar.gz> ;
        dcs:blame <http://drobilla.net/drobilla#me> ;
        dcs:changeset [
            dcs:item [
                rdfs:label "Initial release."
            ]
        ]
    ] ;
    lv2:documentation """

This extension defines a feature, LV2_Extension_Data_Feature, which provides
access to LV2_Descriptor::extension_data() for plugin UIs or other potentially
remote users of a plugin.

Note that the use of this extension by UIs violates the important principle of
UI/plugin separation, and is potentially a source of many problems.
Accordingly, **use of this extension is highly discouraged**, and plugins
should not expect hosts to support it, since it is often impossible to do so.

To support this feature the host must pass an LV2_Feature struct to
LV2_Descriptor::extension_data() with URI LV2_DATA_ACCESS_URI and data pointed
to an instance of LV2_Extension_Data_Feature.

"""^^lv2:Markdown .

)lv2ttl"
}

}
}

};
}
