/*
 *  Licensed to the Apache Software Foundation (ASF) under one or more
 *  contributor license agreements.  See the NOTICE file distributed with
 *  this work for additional information regarding copyright ownership.
 *  The ASF licenses this file to You under the Apache License, Version 2.0
 *  (the "License"); you may not use this file except in compliance with
 *  the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/**
* @author Alexander Y. Kleymenov
*/

package org.apache.harmony.security.tests.java.security.cert;

import java.math.BigInteger;
import java.security.cert.CRLException;
import java.security.cert.X509CRLEntry;
import java.util.Date;
import java.util.Set;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 */

public class X509CRLEntryTest extends TestCase {

    X509CRLEntry tbt_crlentry;

    /**
     * The stub class used for testing of non abstract methods.
     */
    private class TBTCRLEntry extends X509CRLEntry {
        public Set getNonCriticalExtensionOIDs() {
            return null;
        }

        public Set getCriticalExtensionOIDs() {
            return null;
        }

        public byte[] getExtensionValue(String oid) {
            return null;
        }

        public boolean hasUnsupportedCriticalExtension() {
            return false;
        }

        public byte[] getEncoded() throws CRLException {
            return null;
        }

        public BigInteger getSerialNumber() {
            return null;
        }

        public Date getRevocationDate() {
            return null;
        }

        public boolean hasExtensions() {
            return false;
        }

        public String toString() {
            return null;
        }
    }

    public X509CRLEntryTest() {
        tbt_crlentry = new TBTCRLEntry() {
            public byte[] getEncoded() throws CRLException {
                return new byte[] {1, 2, 3};
            }
        };
    }

    /**
     * equals(Object other) method testing. Tests the correctness of equal
     * operation: it should be reflexive, symmetric, transitive, consistent
     * and should be false on null object.
     */
    public void testEquals() {
        TBTCRLEntry tbt_crlentry_1 = new TBTCRLEntry() {
            public byte[] getEncoded() {
                return new byte[] {1, 2, 3};
            }
        };

        TBTCRLEntry tbt_crlentry_2 = new TBTCRLEntry() {
            public byte[] getEncoded() {
                return new byte[] {1, 2, 3};
            }
        };

        TBTCRLEntry tbt_crlentry_3 = new TBTCRLEntry() {
            public byte[] getEncoded() {
                return new byte[] {3, 2, 1};
            }
        };

        // checking for reflexive law:
        assertTrue("The equivalence relation should be reflexive.",
                                            tbt_crlentry.equals(tbt_crlentry));

        assertEquals("The CRL Entries with equals encoded form should be equal",
                                            tbt_crlentry, tbt_crlentry_1);
        // checking for symmetric law:
        assertTrue("The equivalence relation should be symmetric.",
                                            tbt_crlentry_1.equals(tbt_crlentry));

        assertEquals("The CRL Entries with equals encoded form should be equal",
                                            tbt_crlentry_1, tbt_crlentry_2);
        // checking for transitive law:
        assertTrue("The equivalence relation should be transitive.",
                                            tbt_crlentry.equals(tbt_crlentry_2));

        assertFalse("Should not be equal to null object.",
                                            tbt_crlentry.equals(null));

        assertFalse("The CRL Entries with differing encoded form "
                                            + "should not be equal.",
                                            tbt_crlentry.equals(tbt_crlentry_3));
        assertFalse("The CRL Entries should not be equals to the object "
                                + "which is not an instance of X509CRLEntry.",
                                            tbt_crlentry.equals(new Object()));
    }

    /**
     * hashCode() method testing. Tests that for equal objects hash codes
     * are equal.
     */
    public void testHashCode() {
        TBTCRLEntry tbt_crlentry_1 = new TBTCRLEntry() {
            public byte[] getEncoded() {
                return new byte[] {1, 2, 3};
            }
        };
        assertTrue("Equal objects should have the same hash codes.",
                        tbt_crlentry.hashCode() == tbt_crlentry_1.hashCode());
    }

    /**
     * getCertificateIssuer() method testing. Tests if the method throws
     * appropriate exception.
     */
    public void testGetCertificateIssuer() {
        assertNull("The default implementation should return null.", 
                tbt_crlentry.getCertificateIssuer());
    }

    public static Test suite() {
        return new TestSuite(X509CRLEntryTest.class);
    }

    public static void main(String[] args) {
        junit.textui.TestRunner.run(suite());
    }
}

