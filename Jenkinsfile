pipeline {
 agent any
 stages {
     stage ('init'){
         steps {
            print "BUILD_NUMBER: ${env.BUILD_NUMBER}"
            print "BUILD_ID: ${env.BUILD_ID}"
            print "WORKSPACE: ${env.WORKSPACE}"
            print "JENKINS_URL: ${env.JENKINS_URL}"
            print "BUILD_URL: ${env.BUILD_URL}"
            print "JOB_URL: ${env.JOB_URL}"
         }
     }
     stage ('get from SCM'){
         steps {
             git credentialsId: 'fa22ef6d-be81-40ff-8ff4-1c8c36b145f1', url: 'https://github.com/kirin1840/embci_unit_test.git'
         }   
     }
 }
       

/*
node {
    stage('init') {
        print "BUILD_NUMBER: ${env.BUILD_NUMBER}"
        print "BUILD_ID: ${env.BUILD_ID}"
        print "WORKSPACE: ${env.WORKSPACE}"
        print "JENKINS_URL: ${env.JENKINS_URL}"
        print "BUILD_URL: ${env.BUILD_URL}"
        print "JOB_URL: ${env.JOB_URL}"
    }
    stage('get from SCM') {
        git credentialsId: 'fa22ef6d-be81-40ff-8ff4-1c8c36b145f1', url: 'https://github.com/kirin1840/embci_unit_test.git'
    }           
}
*/
