#!/bin/bash

echo "DELETE ALL"

kubectl delete deployment --all --namespace kube-public
kubectl delete service --all --namespace kube-public
kubectl delete pod --all --namespace kube-public
kubectl delete daemonsets.apps --all --namespace kube-public
kubectl delete ingress --all --namespace kube-public

kubectl delete deployment --all
kubectl delete service --all
kubectl delete pod --all
kubectl delete daemonsets.apps --all
kubectl delete ingress --all

kubectl delete pvc --all